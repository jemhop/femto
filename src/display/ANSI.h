#pragma once
#include "displayBuffer.h"

//TODO: ADD OPTIONAL SUPPORT FOR TRUECOLOR OR 256 IF TERM SUPPORTS

//modes
const extern char* ANSI_RESET;
const extern char* ANSI_BOLD;
const extern char* ANSI_FAINT;
const extern char* ANSI_ITALIC;
const extern char* ANSI_UNDERLINE;
const extern char* ANSI_BLINKING;
const extern char* ANSI_INVERSE;
const extern char* ANSI_INVISIBLE ;
const extern char* ANSI_STRIKETHROUGH;


//erase functions
const extern char* ANSI_CLRSCREEN;
const extern char* ANSI_CLRFROMCURSTOSTART;
const extern char* ANSI_CLRFRMCURSORTOSTART;
const extern char* ANSI_CLRENTIRESCREEN;
const extern char* ANSI_CLEARLINE;
const extern char* ANSI_FROMCURSTOENDLINE;
const extern char* ANSI_FROMCURSTOSTARTLINE;
const extern char* ANSI_CLEARENTIRELINE;

//basic foreground color codes

const extern char* ANSI_FBLACK;
const extern char* ANSI_FRED;
const extern char* ANSI_FGREEN;
const extern char* ANSI_FYELLOW;
const extern char* ANSI_FBLUE;
const extern char* ANSI_FMAGENTA;
const extern char* ANSI_FCYAN;
const extern char* ANSI_FWHITE;
const extern char* ANSI_FGRAY;
const extern char* ANSI_RESETALL;

//basic background color codes

const extern char* ANSI_BBLACK;
const extern char* ANSI_BGRED;
const extern char* ANSI_BGREEN;
const extern char* ANSI_BYELLOW;
const extern char* ANSI_BBLUE;
const extern char* ANSI_BMAGENTA;
const extern char* ANSI_BCYAN;
const extern char* ANSI_BWHITE;

//line movement

const extern char* ANSI_CURSORTOHOMEPOS;
const extern char* ANSI_MOVEUP;
const extern char* ANSI_MOVEDOWN;
const extern char* ANSI_MOVERIGHT;
const extern char* ANSI_MOVELEFT;
const extern char* ANSI_MOVEDOWNLINE;const
const extern char* ANSI_MOVEUPLINE;
const extern char* ANSI_MOVETOCOLUMN;
const extern char* ANSI_GETCURSORPOS;
const extern char* ANSI_SAVEPOS;
const extern char* ANSI_GOTOSAVE;

//misc

const extern char* ANSI_CURSORINVIS;
const extern char* ANSI_CURSORVISIBLE;

void ANSIClearColors(struct dispBuff *ab);

int ANSILength(char* code);







