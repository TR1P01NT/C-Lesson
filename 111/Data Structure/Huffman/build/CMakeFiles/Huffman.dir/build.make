# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build"

# Include any dependencies generated for this target.
include CMakeFiles/Huffman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Huffman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Huffman.dir/flags.make

CMakeFiles/Huffman.dir/huffman.c.o: CMakeFiles/Huffman.dir/flags.make
CMakeFiles/Huffman.dir/huffman.c.o: /Users/kevlee/Documents/GitHub/C\ Lesson/111/Data\ Structure/Huffman/huffman.c
CMakeFiles/Huffman.dir/huffman.c.o: CMakeFiles/Huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Huffman.dir/huffman.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Huffman.dir/huffman.c.o -MF CMakeFiles/Huffman.dir/huffman.c.o.d -o CMakeFiles/Huffman.dir/huffman.c.o -c "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/huffman.c"

CMakeFiles/Huffman.dir/huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Huffman.dir/huffman.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/huffman.c" > CMakeFiles/Huffman.dir/huffman.c.i

CMakeFiles/Huffman.dir/huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Huffman.dir/huffman.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/huffman.c" -o CMakeFiles/Huffman.dir/huffman.c.s

# Object files for target Huffman
Huffman_OBJECTS = \
"CMakeFiles/Huffman.dir/huffman.c.o"

# External object files for target Huffman
Huffman_EXTERNAL_OBJECTS =

Huffman: CMakeFiles/Huffman.dir/huffman.c.o
Huffman: CMakeFiles/Huffman.dir/build.make
Huffman: CMakeFiles/Huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Huffman.dir/build: Huffman
.PHONY : CMakeFiles/Huffman.dir/build

CMakeFiles/Huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Huffman.dir/clean

CMakeFiles/Huffman.dir/depend:
	cd "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman" "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman" "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build" "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build" "/Users/kevlee/Documents/GitHub/C Lesson/111/Data Structure/Huffman/build/CMakeFiles/Huffman.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Huffman.dir/depend

