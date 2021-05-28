#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include "editor.h"
#include "../main.h"
#include "../globals.h"
#include "../display/displayBuffer.h"
#include "../display/syntaxhl.h"
#include "../display/displayBuffer.h"
#include "../terminal/editor.h"
#include "../util/stringParser.h"
#include "../input/keypress.h"
#include "../display/ANSI.h"
#include "../display/draw.h"

//TODO: THIS CODE IS FILLED WITH ABSOLUTELY HORRIFIC FUNCTIONS PLEASE REFACTOR THEM EMMA YOU FUCKING FOOL

void editorInsertRow(int pos, char *s, size_t len) {
    struct editorConfig *E = getCurrentConfig();
    if (pos < 0 || pos > E->numrows) return;

    E->row = realloc(E->row, sizeof(erow) * (E->numrows + 1));
    memmove(&E->row[pos + 1], &E->row[pos], sizeof(erow) * (E->numrows - pos));
    for (int i = pos + 1; i <= E->numrows; i++)
        E->row[i].idx++;

    E->row[pos].idx = pos;

    E->row[pos].size = len;
    E->row[pos].chars = malloc(len + 1);
    memcpy(E->row[pos].chars, s, len);
    E->row[pos].chars[len] = '\0';

    E->row[pos].rsize = 0;
    E->row[pos].render = NULL;
    E->row[pos].hl = NULL;
    E->row[pos].hl_open_comment = 0;
    editorUpdateRow(&E->row[pos]);

    E->numrows++;
    E->dirty++;
}

//TODO: editorDrawRows is genuinely the stuff of my nightmares
void editorDrawRows(struct dispBuff *ab) {
    struct editorConfig *E = getCurrentConfig();

    for (int y = 0; y < E->screenrows; y++) {
        int filerow = y + E->scrollYOffset;

        if (filerow >= E->numrows) {
            if (E->numrows == 0 && y == E->screenrows / 3) {
                drawWelcomeMessage(ab);
            }
            else {
                dispBuffAppend(ab, "~", 1);
            }
        }
        else {
            int len = E->row[filerow].rsize - E->scrollXOffset;
            if (len < 0) len = 0;
            if (len > E->screencols) len = E->screencols;

            char *c = &E->row[filerow].render[E->scrollXOffset];
            unsigned char *hl = &E->row[filerow].hl[E->scrollXOffset];
            int current_color = -1;

            for (int j = 0; j < len; j++) {
                //check if control character
                if (iscntrl(c[j])) {
                    char sym = (c[j] <= 26) ? '@' + c[j] : '?';
                    dispBuffAppend(ab, ANSI_INVERSE, 4);
                    dispBuffAppend(ab, &sym, 1);
                    dispBuffAppend(ab, ANSI_RESET, 3);
                    if (current_color != -1) {
                        char buf[16];
                        //set display mode to be color in range of 30+, later replace this to use the char array ANSI_ definitions
                        int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", current_color);
                        dispBuffAppend(ab, buf, clen);
                    }
                }
                else if (hl[j] == HL_NORMAL) {
                    if (current_color != -1) {
                        dispBuffAppend(ab, ANSI_FGRAY, 5);
                        current_color = -1;
                    }
                    dispBuffAppend(ab, &c[j], 1);
                }
                else {
                    int color = editorSyntaxToColor(hl[j]);
                    if (color != current_color) {
                        current_color = color;
                        char buf[16];
                        int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", color);
                        dispBuffAppend(ab, buf, clen);
                    }
                    dispBuffAppend(ab, &c[j], 1);
                }
            }
            dispBuffAppend(ab, ANSI_FGRAY, 5);
        }

        dispBuffAppend(ab, ANSI_CLEARLINE, 3);
        dispBuffAppend(ab, "\r\n", 2);
    }
}

void editorUpdateRow(erow *row) {
    int tabs = 0;
    int j;
    for (j = 0; j < row->size; j++)
        if (row->chars[j] == '\t') tabs++;

    free(row->render);
    row->render = malloc(row->size + tabs*(FEMTO_TAB_STOP - 1) + 1);

    int idx = 0;
    for (j = 0; j < row->size; j++) {
        if (row->chars[j] == '\t') {
            row->render[idx++] = ' ';
            while (idx % FEMTO_TAB_STOP != 0) row->render[idx++] = ' ';
        } else {
            row->render[idx++] = row->chars[j];
        }
    }
    row->render[idx] = '\0';
    row->rsize = idx;

    editorUpdateSyntax(row);
}

void editorRefreshScreen() {
    editorScroll();
    struct editorConfig *E = getCurrentConfig();

    struct dispBuff dispBuff = DISPBUF_INIT;

    dispBuffAppend(&dispBuff, ANSI_CURSORINVIS, 6);
    dispBuffAppend(&dispBuff, ANSI_CURSORTOHOMEPOS, 3);

    editorDrawRows(&dispBuff);
    drawStatusBar(&dispBuff);
    drawMessageBar(&dispBuff);

    char buf[32];
    //setting the position of the cursor i think???
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E->cy - E->scrollYOffset) + 1,
             (E->rx - E->scrollXOffset) + 1);
    dispBuffAppend(&dispBuff, buf, strlen(buf));

    dispBuffAppend(&dispBuff, ANSI_CURSORVISIBLE, 6);

    write(STDOUT_FILENO, dispBuff.text, dispBuff.len);
    dispBuffFree(&dispBuff);
}

void editorUpdateSyntax(erow *row) {
    struct editorConfig *E = getCurrentConfig();
    row->hl = realloc(row->hl, row->rsize);
    memset(row->hl, HL_NORMAL, row->rsize);

    if (E->syntax == NULL) return;

    char **keywords = E->syntax->keywords;

    char *scs = E->syntax->singleline_comment_start;
    char *mcs = E->syntax->multiline_comment_start;
    char *mce = E->syntax->multiline_comment_end;

    int scs_len = scs ? strlen(scs) : 0;
    int mcs_len = mcs ? strlen(mcs) : 0;
    int mce_len = mce ? strlen(mce) : 0;

    int prev_sep = 1;
    int in_string = 0;
    int in_comment = (row->idx > 0 && E->row[row->idx - 1].hl_open_comment);

    int i = 0;
    while (i < row->rsize) {
        char c = row->render[i];
        unsigned char prev_hl = (i > 0) ? row->hl[i - 1] : HL_NORMAL;

        if (scs_len && !in_string && !in_comment) {
            if (!strncmp(&row->render[i], scs, scs_len)) {
                memset(&row->hl[i], HL_COMMENT, row->rsize - i);
                break;
            }
        }

        if (mcs_len && mce_len && !in_string) {
            if (in_comment) {
                row->hl[i] = HL_MLCOMMENT;
                if (!strncmp(&row->render[i], mce, mce_len)) {
                    memset(&row->hl[i], HL_MLCOMMENT, mce_len);
                    i += mce_len;
                    in_comment = 0;
                    prev_sep = 1;
                    continue;
                } else {
                    i++;
                    continue;
                }
            } else if (!strncmp(&row->render[i], mcs, mcs_len)) {
                memset(&row->hl[i], HL_MLCOMMENT, mcs_len);
                i += mcs_len;
                in_comment = 1;
                continue;
            }
        }

        if (E->syntax->flags & HL_HIGHLIGHT_STRINGS) {
            if (in_string) {
                row->hl[i] = HL_STRING;
                if (c == '\\' && i + 1 < row->rsize) {
                    row->hl[i + 1] = HL_STRING;
                    i += 2;
                    continue;
                }
                if (c == in_string) in_string = 0;
                i++;
                prev_sep = 1;
                continue;
            } else {
                if (c == '"' || c == '\'') {
                    in_string = c;
                    row->hl[i] = HL_STRING;
                    i++;
                    continue;
                }
            }
        }

        if (E->syntax->flags & HL_HIGHLIGHT_NUMBERS) {
            if ((isdigit(c) && (prev_sep || prev_hl == HL_NUMBER)) ||
                (c == '.' && prev_hl == HL_NUMBER)) {
                row->hl[i] = HL_NUMBER;
                i++;
                prev_sep = 0;
                continue;
            }
        }

        if (prev_sep) {
            int j;
            for (j = 0; keywords[j]; j++) {
                int klen = strlen(keywords[j]);
                int kw2 = keywords[j][klen - 1] == '|';
                if (kw2) klen--;

                if (!strncmp(&row->render[i], keywords[j], klen) &&
                    is_separator(row->render[i + klen])) {
                    memset(&row->hl[i], kw2 ? HL_KEYWORD2 : HL_KEYWORD1, klen);
                    i += klen;
                    break;
                }
            }
            if (keywords[j] != NULL) {
                prev_sep = 0;
                continue;
            }
        }

        prev_sep = is_separator(c);
        i++;
    }

    int changed = (row->hl_open_comment != in_comment);
    row->hl_open_comment = in_comment;
    if (changed && row->idx + 1 < E->numrows)
        editorUpdateSyntax(&E->row[row->idx + 1]);
}

void editorScroll() {
    struct editorConfig *E = getCurrentConfig();
    E->rx = 0;
    if (E->cy < E->numrows) {
        E->rx = editorRowCxToRx(&E->row[E->cy], E->cx);
    }

    if (E->cy < E->scrollYOffset) {
        E->scrollYOffset = E->cy;
    }
    if (E->cy >= E->scrollYOffset + E->screenrows) {
        E->scrollYOffset = E->cy - E->screenrows + 1;
    }
    if (E->rx < E->scrollXOffset) {
        E->scrollXOffset = E->rx;
    }
    if (E->rx >= E->scrollXOffset + E->screencols) {
        E->scrollXOffset = E->rx - E->screencols + 1;
    }
}

int editorRowCxToRx(erow *row, int cx) {
    int rx = 0;
    int j;
    for (j = 0; j < cx; j++) {
        if (row->chars[j] == '\t')
            rx += (FEMTO_TAB_STOP - 1) - (rx % FEMTO_TAB_STOP);
        rx++;
    }
    return rx;
}

int editorRowRxToCx(erow *row, int rx) {
    int cur_rx = 0;
    int cx;
    for (cx = 0; cx < row->size; cx++) {
        if (row->chars[cx] == '\t')
            cur_rx += (FEMTO_TAB_STOP - 1) - (cur_rx % FEMTO_TAB_STOP);
        cur_rx++;

        if (cur_rx > rx) return cx;
    }
    return cx;
}

void editorInsertNewline() {
    struct editorConfig *E = getCurrentConfig();
    if (E->cx == 0) {
        editorInsertRow(E->cy, "", 0);
    } else {
        erow *row = &E->row[E->cy];
        editorInsertRow(E->cy + 1, &row->chars[E->cx], row->size - E->cx);
        row = &E->row[E->cy];
        row->size = E->cx;
        row->chars[row->size] = '\0';
        editorUpdateRow(row);
    }
    E->cy++;
    E->cx = 0;
}


void editorDelChar() {
    struct editorConfig *E = getCurrentConfig();
    if (E->cy == E->numrows) return;
    if (E->cx == 0 && E->cy == 0) return;

    erow *row = &E->row[E->cy];
    if (E->cx > 0) {
        editorRowDelChar(row, E->cx - 1);
        E->cx--;
    } else {
        E->cx = E->row[E->cy - 1].size;
        editorRowAppendString(&E->row[E->cy - 1], row->chars, row->size);
        editorDelRow(E->cy);
        E->cy--;
    }
}



void editorRowDelChar(erow *row, int at) {
    struct editorConfig *E = getCurrentConfig();
    if (at < 0 || at >= row->size) return;
    memmove(&row->chars[at], &row->chars[at + 1], row->size - at);
    row->size--;
    editorUpdateRow(row);
    E->dirty++;
}


void editorRowAppendString(erow *row, char *s, size_t len) {
    struct editorConfig *E = getCurrentConfig();
    row->chars = realloc(row->chars, row->size + len + 1);
    memcpy(&row->chars[row->size], s, len);
    row->size += len;
    row->chars[row->size] = '\0';
    editorUpdateRow(row);
    E->dirty++;
}


void editorDelRow(int at) {
    struct editorConfig *E = getCurrentConfig();
    if (at < 0 || at >= E->numrows) return;
    editorFreeRow(&E->row[at]);
    memmove(&E->row[at], &E->row[at + 1], sizeof(erow) * (E->numrows - at - 1));
    for (int j = at; j < E->numrows - 1; j++) E->row[j].idx--;
    E->numrows--;
    E->dirty++;
}


void editorFreeRow(erow *row) {
    free(row->render);
    free(row->chars);
    free(row->hl);
}


char *editorRowsToString(int *buflen) {
    struct editorConfig *E = getCurrentConfig();
    int totlen = 0;
    int j;
    for (j = 0; j < E->numrows; j++)
        totlen += E->row[j].size + 1;
    *buflen = totlen;

    char *buf = malloc(totlen);
    char *p = buf;
    for (j = 0; j < E->numrows; j++) {
        memcpy(p, E->row[j].chars, E->row[j].size);
        p += E->row[j].size;
        *p = '\n';
        p++;
    }

    return buf;
}

void editorFind() {
    struct editorConfig *E = getCurrentConfig();
    int saved_cx = E->cx;
    int saved_cy = E->cy;
    int saved_coloff = E->scrollXOffset;
    int saved_rowoff = E->scrollYOffset;

    char *query = editorPrompt("Search: %s (Use ESC/Arrows/Enter)",
                               editorFindCallback);

    if (query) {
        free(query);
    } else {
        E->cx = saved_cx;
        E->cy = saved_cy;
        E->scrollXOffset = saved_coloff;
        E->scrollYOffset = saved_rowoff;
    }
}

void editorFindCallback(char *query, int key) {
    struct editorConfig *E = getCurrentConfig();
    static int last_match = -1;
    static int direction = 1;

    static int saved_hl_line;
    static char *saved_hl = NULL;

    if (saved_hl) {
        memcpy(E->row[saved_hl_line].hl, saved_hl, E->row[saved_hl_line].rsize);
        free(saved_hl);
        saved_hl = NULL;
    }

    if (key == '\r' || key == '\x1b') {
        last_match = -1;
        direction = 1;
        return;
    } else if (key == ARROW_RIGHT || key == ARROW_DOWN) {
        direction = 1;
    } else if (key == ARROW_LEFT || key == ARROW_UP) {
        direction = -1;
    } else {
        last_match = -1;
        direction = 1;
    }

    if (last_match == -1) direction = 1;
    int current = last_match;
    int i;
    for (i = 0; i < E->numrows; i++) {
        current += direction;
        if (current == -1) current = E->numrows - 1;
        else if (current == E->numrows) current = 0;

        erow *row = &E->row[current];
        char *match = strstr(row->render, query);
        if (match) {
            last_match = current;
            E->cy = current;
            E->cx = editorRowRxToCx(row, match - row->render);
            E->scrollYOffset = E->numrows;

            saved_hl_line = current;
            saved_hl = malloc(row->rsize);
            memcpy(saved_hl, row->hl, row->rsize);
            memset(&row->hl[match - row->render], HL_MATCH, strlen(query));
            break;
        }
    }
}

void moveCursor(int key) {
    struct editorConfig *E = getCurrentConfig();
    erow *row = (E->cy >= E->numrows) ? NULL : &E->row[E->cy];

    switch (key) {
        case ARROW_LEFT:
            if (E->cx != 0) {
                E->cx--;
            } else if (E->cy > 0) {
                E->cy--;
                E->cx = E->row[E->cy].size;
            }
            break;
        case ARROW_RIGHT:
            if (row && E->cx < row->size) {
                E->cx++;
            } else if (row && E->cx == row->size) {
                E->cy++;
                E->cx = 0;
            }
            break;
        case ARROW_UP:
            if (E->cy != 0) {
                E->cy--;
            }
            break;
        case ARROW_DOWN:
            if (E->cy < E->numrows) {
                E->cy++;
            }
            break;
    }

    row = (E->cy >= E->numrows) ? NULL : &E->row[E->cy];
    int rowlen = row ? row->size : 0;
    if (E->cx > rowlen) {
        E->cx = rowlen;
    }
}

void insertChar(int c) {
    struct editorConfig *E = getCurrentConfig();
    if (E->cy == E->numrows) {
        editorInsertRow(E->numrows, "", 0);
    }
    rowInsertChar(&E->row[E->cy], E->cx, c);
    E->cx++;
}

void rowInsertChar(erow *row, int at, int c) {
    struct editorConfig *E = getCurrentConfig();
    if (at < 0 || at > row->size) at = row->size;
    row->chars = realloc(row->chars, row->size + 2);
    memmove(&row->chars[at + 1], &row->chars[at], row->size - at + 1);
    row->size++;
    row->chars[at] = c;
    editorUpdateRow(row);
    E->dirty++;
}















