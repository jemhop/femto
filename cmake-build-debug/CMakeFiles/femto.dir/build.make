# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jemhop/CLionProjects/femto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jemhop/CLionProjects/femto/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/femto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/femto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/femto.dir/flags.make

CMakeFiles/femto.dir/src/main.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/femto.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/main.c.o -c /home/jemhop/CLionProjects/femto/src/main.c

CMakeFiles/femto.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/main.c > CMakeFiles/femto.dir/src/main.c.i

CMakeFiles/femto.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/main.c -o CMakeFiles/femto.dir/src/main.c.s

CMakeFiles/femto.dir/src/terminal/terminal.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/terminal/terminal.c.o: ../src/terminal/terminal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/femto.dir/src/terminal/terminal.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/terminal/terminal.c.o -c /home/jemhop/CLionProjects/femto/src/terminal/terminal.c

CMakeFiles/femto.dir/src/terminal/terminal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/terminal/terminal.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/terminal/terminal.c > CMakeFiles/femto.dir/src/terminal/terminal.c.i

CMakeFiles/femto.dir/src/terminal/terminal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/terminal/terminal.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/terminal/terminal.c -o CMakeFiles/femto.dir/src/terminal/terminal.c.s

CMakeFiles/femto.dir/src/util/file.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/util/file.c.o: ../src/util/file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/femto.dir/src/util/file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/util/file.c.o -c /home/jemhop/CLionProjects/femto/src/util/file.c

CMakeFiles/femto.dir/src/util/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/util/file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/util/file.c > CMakeFiles/femto.dir/src/util/file.c.i

CMakeFiles/femto.dir/src/util/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/util/file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/util/file.c -o CMakeFiles/femto.dir/src/util/file.c.s

CMakeFiles/femto.dir/src/terminal/editor.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/terminal/editor.c.o: ../src/terminal/editor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/femto.dir/src/terminal/editor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/terminal/editor.c.o -c /home/jemhop/CLionProjects/femto/src/terminal/editor.c

CMakeFiles/femto.dir/src/terminal/editor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/terminal/editor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/terminal/editor.c > CMakeFiles/femto.dir/src/terminal/editor.c.i

CMakeFiles/femto.dir/src/terminal/editor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/terminal/editor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/terminal/editor.c -o CMakeFiles/femto.dir/src/terminal/editor.c.s

CMakeFiles/femto.dir/src/display/displayBuffer.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/display/displayBuffer.c.o: ../src/display/displayBuffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/femto.dir/src/display/displayBuffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/display/displayBuffer.c.o -c /home/jemhop/CLionProjects/femto/src/display/displayBuffer.c

CMakeFiles/femto.dir/src/display/displayBuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/display/displayBuffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/display/displayBuffer.c > CMakeFiles/femto.dir/src/display/displayBuffer.c.i

CMakeFiles/femto.dir/src/display/displayBuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/display/displayBuffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/display/displayBuffer.c -o CMakeFiles/femto.dir/src/display/displayBuffer.c.s

CMakeFiles/femto.dir/src/display/syntaxhl.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/display/syntaxhl.c.o: ../src/display/syntaxhl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/femto.dir/src/display/syntaxhl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/display/syntaxhl.c.o -c /home/jemhop/CLionProjects/femto/src/display/syntaxhl.c

CMakeFiles/femto.dir/src/display/syntaxhl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/display/syntaxhl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/display/syntaxhl.c > CMakeFiles/femto.dir/src/display/syntaxhl.c.i

CMakeFiles/femto.dir/src/display/syntaxhl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/display/syntaxhl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/display/syntaxhl.c -o CMakeFiles/femto.dir/src/display/syntaxhl.c.s

CMakeFiles/femto.dir/src/util/stringParser.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/util/stringParser.c.o: ../src/util/stringParser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/femto.dir/src/util/stringParser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/util/stringParser.c.o -c /home/jemhop/CLionProjects/femto/src/util/stringParser.c

CMakeFiles/femto.dir/src/util/stringParser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/util/stringParser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/util/stringParser.c > CMakeFiles/femto.dir/src/util/stringParser.c.i

CMakeFiles/femto.dir/src/util/stringParser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/util/stringParser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/util/stringParser.c -o CMakeFiles/femto.dir/src/util/stringParser.c.s

CMakeFiles/femto.dir/src/input/keypress.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/input/keypress.c.o: ../src/input/keypress.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/femto.dir/src/input/keypress.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/input/keypress.c.o -c /home/jemhop/CLionProjects/femto/src/input/keypress.c

CMakeFiles/femto.dir/src/input/keypress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/input/keypress.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/input/keypress.c > CMakeFiles/femto.dir/src/input/keypress.c.i

CMakeFiles/femto.dir/src/input/keypress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/input/keypress.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/input/keypress.c -o CMakeFiles/femto.dir/src/input/keypress.c.s

CMakeFiles/femto.dir/src/display/ANSI.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/display/ANSI.c.o: ../src/display/ANSI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/femto.dir/src/display/ANSI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/display/ANSI.c.o -c /home/jemhop/CLionProjects/femto/src/display/ANSI.c

CMakeFiles/femto.dir/src/display/ANSI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/display/ANSI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/display/ANSI.c > CMakeFiles/femto.dir/src/display/ANSI.c.i

CMakeFiles/femto.dir/src/display/ANSI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/display/ANSI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/display/ANSI.c -o CMakeFiles/femto.dir/src/display/ANSI.c.s

CMakeFiles/femto.dir/src/util/stringUtil.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/util/stringUtil.c.o: ../src/util/stringUtil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/femto.dir/src/util/stringUtil.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/util/stringUtil.c.o -c /home/jemhop/CLionProjects/femto/src/util/stringUtil.c

CMakeFiles/femto.dir/src/util/stringUtil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/util/stringUtil.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/util/stringUtil.c > CMakeFiles/femto.dir/src/util/stringUtil.c.i

CMakeFiles/femto.dir/src/util/stringUtil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/util/stringUtil.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/util/stringUtil.c -o CMakeFiles/femto.dir/src/util/stringUtil.c.s

CMakeFiles/femto.dir/src/display/draw.c.o: CMakeFiles/femto.dir/flags.make
CMakeFiles/femto.dir/src/display/draw.c.o: ../src/display/draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/femto.dir/src/display/draw.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/femto.dir/src/display/draw.c.o -c /home/jemhop/CLionProjects/femto/src/display/draw.c

CMakeFiles/femto.dir/src/display/draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/femto.dir/src/display/draw.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/src/display/draw.c > CMakeFiles/femto.dir/src/display/draw.c.i

CMakeFiles/femto.dir/src/display/draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/femto.dir/src/display/draw.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/src/display/draw.c -o CMakeFiles/femto.dir/src/display/draw.c.s

# Object files for target femto
femto_OBJECTS = \
"CMakeFiles/femto.dir/src/main.c.o" \
"CMakeFiles/femto.dir/src/terminal/terminal.c.o" \
"CMakeFiles/femto.dir/src/util/file.c.o" \
"CMakeFiles/femto.dir/src/terminal/editor.c.o" \
"CMakeFiles/femto.dir/src/display/displayBuffer.c.o" \
"CMakeFiles/femto.dir/src/display/syntaxhl.c.o" \
"CMakeFiles/femto.dir/src/util/stringParser.c.o" \
"CMakeFiles/femto.dir/src/input/keypress.c.o" \
"CMakeFiles/femto.dir/src/display/ANSI.c.o" \
"CMakeFiles/femto.dir/src/util/stringUtil.c.o" \
"CMakeFiles/femto.dir/src/display/draw.c.o"

# External object files for target femto
femto_EXTERNAL_OBJECTS =

femto: CMakeFiles/femto.dir/src/main.c.o
femto: CMakeFiles/femto.dir/src/terminal/terminal.c.o
femto: CMakeFiles/femto.dir/src/util/file.c.o
femto: CMakeFiles/femto.dir/src/terminal/editor.c.o
femto: CMakeFiles/femto.dir/src/display/displayBuffer.c.o
femto: CMakeFiles/femto.dir/src/display/syntaxhl.c.o
femto: CMakeFiles/femto.dir/src/util/stringParser.c.o
femto: CMakeFiles/femto.dir/src/input/keypress.c.o
femto: CMakeFiles/femto.dir/src/display/ANSI.c.o
femto: CMakeFiles/femto.dir/src/util/stringUtil.c.o
femto: CMakeFiles/femto.dir/src/display/draw.c.o
femto: CMakeFiles/femto.dir/build.make
femto: CMakeFiles/femto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable femto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/femto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/femto.dir/build: femto

.PHONY : CMakeFiles/femto.dir/build

CMakeFiles/femto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/femto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/femto.dir/clean

CMakeFiles/femto.dir/depend:
	cd /home/jemhop/CLionProjects/femto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jemhop/CLionProjects/femto /home/jemhop/CLionProjects/femto /home/jemhop/CLionProjects/femto/cmake-build-debug /home/jemhop/CLionProjects/femto/cmake-build-debug /home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles/femto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/femto.dir/depend

