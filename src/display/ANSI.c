#include <string.h>
#include "ANSI.h"
#include "displayBuffer.h"

const char* ANSI_RESET = "\x1b[0m";
const char* ANSI_BOLD = "\x1b[1m";
const char* ANSI_FAINT = "\x1b[2m";
const char* ANSI_ITALIC = "\x1b[3m";
const char* ANSI_UNDERLINE = "\x1b[4m";
const char* ANSI_BLINKING = "\x1b[5m";
const char* ANSI_INVERSE = "\x1b[7m";
const char* ANSI_INVISIBLE = "\x1b[[8m";
const char* ANSI_STRIKETHROUGH = "\x1b[9m";


//erase functions
const char* ANSI_CLRSCREEN = "\x1b[J";
const char* ANSI_CLRFROMCURSTOSTART = "\x1b[0J";
const char* ANSI_CLRFRMCURSORTOSTART = "\x1b[1J";
const char* ANSI_CLRENTIRESCREEN = "\x1b[2J";
const char* ANSI_CLEARLINE = "\x1b[K";
const char* ANSI_FROMCURSTOENDLINE = "\x1b[0K";
const char* ANSI_FROMCURSTOSTARTLINE = "\x1b[1K";
const char* ANSI_CLEARENTIRELINE = "\x1b[2K";

//basic foreground color codes

const char* ANSI_FBLACK = "\x1b[30m";
const char* ANSI_FRED =  "\x1b[31m";
const char* ANSI_FGREEN =  "\x1b[32m";
const char* ANSI_FYELLOW =  "\x1b[33m";
const char* ANSI_FBLUE = "\x1b[34m";
const char* ANSI_FMAGENTA = "\x1b[35m";
const char* ANSI_FCYAN =  "\x1b[36m";
const char* ANSI_FWHITE = "\x1b[37m";
const char* ANSI_FGRAY = "\x1b[39m";
const char* ANSI_RESETALL = "\x1b[0m";
//basic background color codes

const char* ANSI_BBLACK  = "\x1b[40m";
const char* ANSI_BGRED  = "\x1b[41m";
const char* ANSI_BGREEN  = "\x1b[42m";
const char* ANSI_BYELLOW  = "\x1b[43m";
const char* ANSI_BBLUE  = "\x1b[44m";
const char* ANSI_BMAGENTA  = "\x1b[45m";
const char* ANSI_BCYAN  = "\x1b[46m";
const char* ANSI_BWHITE  = "\x1b[47m";

const char* ANSI_CURSORTOHOMEPOS = "\x1b[H";const
const char* ANSI_MOVEUP = "\x1b[%sA";
const char* ANSI_MOVEDOWN = "\x1b[%sB";
const char* ANSI_MOVERIGHT = "\x1b[%sC";
const char* ANSI_MOVELEFT = "\x1b[%sD";
const char* ANSI_MOVEDOWNLINE = "\x1b[%sE";
const char* ANSI_MOVEUPLINE = "\x1b[%sF";
const char* ANSI_MOVETOCOLUMN = "\x1b[%sG";
const char* ANSI_GETCURSORPOS = "\x1b[6n";
const char* ANSI_SAVEPOS = "\x1b[s";
const char* ANSI_GOTOSAVE = "\x1b[u";

//misc

const char* ANSI_CURSORINVIS = "\x1b[?25l";
const char* ANSI_CURSORVISIBLE = "\x1b[?25h";

void ANSIClearColors(struct dispBuff *ab) {
    dispBuffAppend(ab, ANSI_RESETALL, 5);
}

//gets length in the way that dispbuff append uses it, for some reason its every value after \x1b + 1
int ANSILength(char* code) {
    int iReturn = 0;
    for(int i = 0; i < strlen(code); i++) {
        if(i>3) {
            iReturn++;
        }
    }
    return iReturn + 1;
}



