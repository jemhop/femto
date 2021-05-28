cmake_minimum_required(VERSION 3.19)
project(femto C)

set(CMAKE_C_STANDARD 11)

add_executable(femto src/main.c src/main.h src/terminal/terminal.c src/terminal/terminal.h src/util/file.c src/util/file.h src/terminal/editor.c src/terminal/editor.h src/globals.h src/display/displayBuffer.c src/display/displayBuffer.h src/display/syntaxhl.c src/display/syntaxhl.h src/util/stringParser.c src/util/stringParser.h src/input/keypress.c src/input/keypress.h src/display/ANSI.c src/display/ANSI.h src/util/stringUtil.c src/util/stringUtil.h src/display/draw.c src/display/draw.h)