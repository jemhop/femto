#pragma once
#include "../main.h"

void enableRawMode(struct editorConfig *E);

void disableRawMode();

int getCursorPosition(int *rows, int *cols);

int getWindowSize(int *rows, int *cols);