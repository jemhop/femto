#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "file.h"
#include "../main.h"
#include "../terminal/editor.h"
#include "../display/syntaxhl.h"

void openFile(char *filename) {
    struct editorConfig *E = getCurrentConfig();
    free(E->filename);
    E->filename = strdup(filename);

    editorSelectSyntaxHighlight();

    FILE *fp = fopen(filename, "r");
    if (fp) {
        char *line = NULL;
        size_t linecap = 0;
        ssize_t linelen;
        while ((linelen = getline(&line, &linecap, fp)) != -1) {
            while (linelen > 0 && (line[linelen - 1] == '\n' ||
                                   line[linelen - 1] == '\r'))
                linelen--;
            editorInsertRow(E->numrows, line, linelen);
        }
        free(line);
        fclose(fp);
        E->dirty = 0;
    }

}

void saveFile() {
    struct editorConfig *E = getCurrentConfig();
    if (E->filename == NULL) {
        E->filename = editorPrompt("Save as: %s (ESC to cancel)", NULL);
        if (E->filename == NULL) {
            setStatusMessage("Save aborted");
            return;
        }
        editorSelectSyntaxHighlight();
    }

    int len;
    char *buf = editorRowsToString(&len);

    int fd = open(E->filename, O_RDWR | O_CREAT, 0644);
    if (fd != -1) {
        if (ftruncate(fd, len) != -1) {
            if (write(fd, buf, len) == len) {
                close(fd);
                free(buf);
                E->dirty = 0;
                setStatusMessage("%d bytes written to disk", len);
                return;
            }
        }
        close(fd);
    }

    free(buf);
    setStatusMessage("Can't save! I/O error: %s", strerror(errno));
}