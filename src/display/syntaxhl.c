#include <stddef.h>
#include <string.h>
#include "syntaxhl.h"
#include "../main.h"
#include "../terminal/editor.h"

char *C_HL_extensions[] = { ".c", ".h", ".cpp", NULL };
char *C_HL_keywords[] = {
        "switch", "if", "while", "for", "break", "continue", "return", "else",
        "struct", "union", "typedef", "static", "enum", "class", "case",

        "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
        "void|", NULL
};

struct editorSyntax HLDB[] = {
        {
                "c",
                C_HL_extensions,
                C_HL_keywords,
                "//", "/*", "*/",
                HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
        },
};


int editorSyntaxToColor(int hl) {
    switch (hl) {
        case HL_COMMENT:
        case HL_MLCOMMENT: return 36;
        case HL_KEYWORD1: return 33;
        case HL_KEYWORD2: return 32;
        case HL_STRING: return 35;
        case HL_NUMBER: return 31;
        case HL_MATCH: return 34;
        default: return 37;
    }
}

void editorSelectSyntaxHighlight() {
    struct editorConfig *E = getCurrentConfig();
    E->syntax = NULL;
    if (E->filename == NULL) return;

    for (unsigned int j = 0; j < HLDB_ENTRIES; j++) {
        struct editorSyntax *s = &HLDB[j];
        unsigned int i = 0;
        while (s->filematch[i]) {
            char *p = strstr(E->filename, s->filematch[i]);
            if (p != NULL) {
                int patlen = strlen(s->filematch[i]);
                if (s->filematch[i][0] != '.' || p[patlen] == '\0') {
                    E->syntax = s;

                    int filerow;
                    for (filerow = 0; filerow < E->numrows; filerow++) {
                        editorUpdateSyntax(&E->row[filerow]);
                    }

                    return;
                }
            }
            i++;
        }
    }
}


