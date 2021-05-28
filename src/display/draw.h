#pragma once
#include "displayBuffer.h"

void drawStatusBar(struct dispBuff *ab);
void setStatusMessage(const char *fmt, ...);
void drawMessageBar(struct dispBuff *ab);
char *editorPrompt(char *prompt, void (*callback)(char *, int));
void drawWelcomeMessage(struct dispBuff *ab);