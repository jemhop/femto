#pragma once

struct dispBuff {
    char *text;
    int len;
};

void dispBuffAppend(struct dispBuff *ab, const char *s, int len);

void dispBuffFree(struct dispBuff *ab);


#define DISPBUF_INIT {NULL, 0}
