#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "terminal.h"
#include "../main.h"


void enableRawMode(struct editorConfig *E) {
        if (tcgetattr(STDIN_FILENO, &E->orig_termios) == -1) die("tcgetattr");
        atexit(disableRawMode);

        struct termios raw = E->orig_termios;
        raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        raw.c_oflag &= ~(OPOST);
        raw.c_cflag |= (CS8);
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        raw.c_cc[VMIN] = 0;
        raw.c_cc[VTIME] = 1;

        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

void disableRawMode() {
    struct editorConfig *E = getCurrentConfig();
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E->orig_termios) == -1)
        die("tcsetattr");
}

int getWindowSize(int *rows, int *cols) {
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;
        return getCursorPosition(rows, cols);
    } else {
        *cols = ws.ws_col;
        *rows = ws.ws_row;
        return 0;
    }
}

int getCursorPosition(int *rows, int *cols) {
    char buf[32];
    unsigned int i = 0;

    if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

    while (i < sizeof(buf) - 1) {
        if (read(STDIN_FILENO, &buf[i], 1) != 1) break;
        if (buf[i] == 'R') break;
        i++;
    }
    buf[i] = '\0';

    if (buf[0] != '\x1b' || buf[1] != '[') return -1;
    if (sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;

    return 0;
}
