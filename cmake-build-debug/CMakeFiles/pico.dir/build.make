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
include CMakeFiles/pico.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pico.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pico.dir/flags.make

CMakeFiles/pico.dir/main.c.o: CMakeFiles/pico.dir/flags.make
CMakeFiles/pico.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pico.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pico.dir/main.c.o -c /home/jemhop/CLionProjects/femto/main.c

CMakeFiles/pico.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pico.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jemhop/CLionProjects/femto/main.c > CMakeFiles/pico.dir/main.c.i

CMakeFiles/pico.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pico.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jemhop/CLionProjects/femto/main.c -o CMakeFiles/pico.dir/main.c.s

# Object files for target pico
pico_OBJECTS = \
"CMakeFiles/pico.dir/main.c.o"

# External object files for target pico
pico_EXTERNAL_OBJECTS =

pico: CMakeFiles/pico.dir/main.c.o
pico: CMakeFiles/pico.dir/build.make
pico: CMakeFiles/pico.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pico"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pico.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pico.dir/build: pico

.PHONY : CMakeFiles/pico.dir/build

CMakeFiles/pico.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pico.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pico.dir/clean

CMakeFiles/pico.dir/depend:
	cd /home/jemhop/CLionProjects/femto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jemhop/CLionProjects/femto /home/jemhop/CLionProjects/femto /home/jemhop/CLionProjects/femto/cmake-build-debug /home/jemhop/CLionProjects/femto/cmake-build-debug /home/jemhop/CLionProjects/femto/cmake-build-debug/CMakeFiles/pico.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pico.dir/depend

