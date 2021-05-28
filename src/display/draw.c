#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include "draw.h"
#include "displayBuffer.h"
#include "../main.h"
#include "syntaxhl.h"
#include "../terminal/editor.h"
#include "../input/keypress.h"
#include "../globals.h"

void drawStatusBar(struct dispBuff *ab) {
    struct editorConfig *E = getCurrentConfig();
    dispBuffAppend(ab, "\x1b[7m", 4);
    char status[80], rstatus[80];
    int len = snprintf(status, sizeof(status), "%.20s - %d lines %s",
                       E->filename ? E->filename : "[No Name]", E->numrows,
                       E->dirty ? "(modified)" : "");
    int rlen = snprintf(rstatus, sizeof(rstatus), "%s | %d/%d",
                        E->syntax ? E->syntax->filetype : "no ft", E->cy + 1, E->numrows);
    if (len > E->screencols) len = E->screencols;
    dispBuffAppend(ab, status, len);
    while (len < E->screencols) {
        if (E->screencols - len == rlen) {
            dispBuffAppend(ab, rstatus, rlen);
            break;
        } else {
            dispBuffAppend(ab, " ", 1);
            len++;
        }
    }
    dispBuffAppend(ab, "\x1b[m", 3);
    dispBuffAppend(ab, "\r\n", 2);
}

void setStatusMessage(const char *fmt, ...) {
    struct editorConfig *E = getCurrentConfig();
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(E->statusmsg, sizeof(E->statusmsg), fmt, ap);
    va_end(ap);
    E->statusmsg_time = time(NULL);
}

char *editorPrompt(char *prompt, void (*callback)(char *, int)) {
    size_t bufsize = 128;
    char *buf = malloc(bufsize);

    size_t buflen = 0;
    buf[0] = '\0';

    while (1) {
        setStatusMessage(prompt, buf);
        editorRefreshScreen();

        int c = editorReadKey();
        if (c == DEL_KEY || c == CTRL_KEY('h') || c == BACKSPACE) {
            if (buflen != 0) buf[--buflen] = '\0';
        } else if (c == '\x1b') {
            setStatusMessage("");
            if (callback) callback(buf, c);
            free(buf);
            return NULL;
        } else if (c == '\r') {
            if (buflen != 0) {
                setStatusMessage("");
                if (callback) callback(buf, c);
                return buf;
            }
        } else if (!iscntrl(c) && c < 128) {
            if (buflen == bufsize - 1) {
                bufsize *= 2;
                buf = realloc(buf, bufsize);
            }
            buf[buflen++] = c;
            buf[buflen] = '\0';
        }

        if (callback) callback(buf, c);
    }
}

void drawMessageBar(struct dispBuff *ab) {
    struct editorConfig *E = getCurrentConfig();
    dispBuffAppend(ab, "\x1b[K", 3);
    int msglen = strlen(E->statusmsg);
    if (msglen > E->screencols) msglen = E->screencols;
    if (msglen && time(NULL) - E->statusmsg_time < 5)
        dispBuffAppend(ab, E->statusmsg, msglen);
}

void drawWelcomeMessage(struct dispBuff *ab) {
    struct editorConfig *E = getCurrentConfig();
    char welcome[80];
    int welcomelen = snprintf(welcome, sizeof(welcome),
                              "Femto editor -- version %s", FEMTO_VERSION);
    if (welcomelen > E->screencols) welcomelen = E->screencols;
    int padding = (E->screencols - welcomelen) / 2;
    if (padding) {
        dispBuffAppend(ab, "~", 1);
        padding--;
    }
    while (padding--) dispBuffAppend(ab, " ", 1);
    dispBuffAppend(ab, welcome, welcomelen);
}



