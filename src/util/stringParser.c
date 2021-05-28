#include <ctype.h>
#include <string.h>
#include "stringParser.h"

int is_separator(int c) {
    return isspace(c) || c == '\0' || strchr(",.()+-/*=~%<>[];", c) != NULL;
}
