#include <string.h>
#include <malloc.h>
#include "displayBuffer.h"


void dispBuffAppend(struct dispBuff *ab, const char *s, int len) {
    char *new = realloc(ab->text, ab->len + len);

    if (new == NULL) return;
    memcpy(&new[ab->len], s, len);
    ab->text = new;
    ab->len += len;
}

void dispBuffFree(struct dispBuff *ab) {
    free(ab->text);
}
