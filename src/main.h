#pragma once

#include <bits/types/time_t.h>
#include <termios.h>

void die(char *output);

void initEditor();

struct editorConfig *getCurrentConfig();


typedef struct erow {
    int idx;
    int size;
    int rsize;
    char *chars;
    char *render;
    unsigned char *hl;
    int hl_open_comment;
} erow;


typedef struct editorConfig {
    int cx, cy;
    //rx is into the render field, cx is into the editor field
    int rx;
    int scrollYOffset;
    int scrollXOffset;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};

