#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "terminal/terminal.h"
#include "globals.h"
#include "util/file.h"
#include "terminal/editor.h"
#include "input/keypress.h"

struct editorConfig E;

int main(int argc, char *argv[]) {
    initEditor();
    enableRawMode(&E);

    if (argc >= 2) {
        openFile(argv[1]);
    }

    setStatusMessage(
            "HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }


    disableRawMode();
    return 0;
}

void initEditor() {
    E.cx = 0;
    E.cy = 0;
    E.rx = 0;
    E.scrollYOffset = 0;
    E.scrollXOffset = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    E.statusmsg[0] = '\0';
    E.statusmsg_time = 0;
    E.syntax = NULL;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
    E.screenrows -= 2;
}

void die(char *output) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    disableRawMode();
    perror(output);
    exit(1);
}

struct editorConfig *getCurrentConfig() {
    return &E;
}
