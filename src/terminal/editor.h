#pragma once
#include "../main.h"
#include "../display/displayBuffer.h"

void editorInsertRow(int pos, char *s, size_t len);

void editorInsertNewline();

void setStatusMessage(const char *fmt, ...);

void editorDelChar();

void editorScroll();

void editorRowDelChar(erow *row, int at);

void editorRowAppendString(erow *row, char *s, size_t len);

void editorDelRow(int at);

void editorFreeRow(erow *row);

char *editorPrompt(char *prompt, void (*callback)(char *, int));

int editorRowCxToRx(erow *row, int cx);

void editorRefreshScreen();

void editorDrawRows(struct dispBuff *ab);

void editorUpdateRow(erow *row);

void editorUpdateSyntax(erow *row);

char *editorRowsToString(int *buflen);

void editorFindCallback(char *query, int key);

void editorFind();

void moveCursor(int key);

void insertChar(int c);

void rowInsertChar(erow *row, int at, int c);

void drawStatusBar(struct dispBuff *ab);

void drawMessageBar(struct dispBuff *ab);