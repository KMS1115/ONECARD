# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /snap/clion/322/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/322/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pc/CLionProjects/OneCard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pc/CLionProjects/OneCard/cmake-build-debug

# Include any dependencies generated for this target.
include RULE/CMakeFiles/RULE.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include RULE/CMakeFiles/RULE.dir/compiler_depend.make

# Include the progress variables for this target.
include RULE/CMakeFiles/RULE.dir/progress.make

# Include the compile flags for this target's objects.
include RULE/CMakeFiles/RULE.dir/flags.make

RULE/CMakeFiles/RULE.dir/src/Card.cpp.o: RULE/CMakeFiles/RULE.dir/flags.make
RULE/CMakeFiles/RULE.dir/src/Card.cpp.o: /home/pc/CLionProjects/OneCard/RULE/src/Card.cpp
RULE/CMakeFiles/RULE.dir/src/Card.cpp.o: RULE/CMakeFiles/RULE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pc/CLionProjects/OneCard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object RULE/CMakeFiles/RULE.dir/src/Card.cpp.o"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT RULE/CMakeFiles/RULE.dir/src/Card.cpp.o -MF CMakeFiles/RULE.dir/src/Card.cpp.o.d -o CMakeFiles/RULE.dir/src/Card.cpp.o -c /home/pc/CLionProjects/OneCard/RULE/src/Card.cpp

RULE/CMakeFiles/RULE.dir/src/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RULE.dir/src/Card.cpp.i"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/CLionProjects/OneCard/RULE/src/Card.cpp > CMakeFiles/RULE.dir/src/Card.cpp.i

RULE/CMakeFiles/RULE.dir/src/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RULE.dir/src/Card.cpp.s"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/CLionProjects/OneCard/RULE/src/Card.cpp -o CMakeFiles/RULE.dir/src/Card.cpp.s

RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o: RULE/CMakeFiles/RULE.dir/flags.make
RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o: /home/pc/CLionProjects/OneCard/RULE/src/Deck.cpp
RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o: RULE/CMakeFiles/RULE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pc/CLionProjects/OneCard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o -MF CMakeFiles/RULE.dir/src/Deck.cpp.o.d -o CMakeFiles/RULE.dir/src/Deck.cpp.o -c /home/pc/CLionProjects/OneCard/RULE/src/Deck.cpp

RULE/CMakeFiles/RULE.dir/src/Deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RULE.dir/src/Deck.cpp.i"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/CLionProjects/OneCard/RULE/src/Deck.cpp > CMakeFiles/RULE.dir/src/Deck.cpp.i

RULE/CMakeFiles/RULE.dir/src/Deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RULE.dir/src/Deck.cpp.s"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/CLionProjects/OneCard/RULE/src/Deck.cpp -o CMakeFiles/RULE.dir/src/Deck.cpp.s

RULE/CMakeFiles/RULE.dir/src/Game.cpp.o: RULE/CMakeFiles/RULE.dir/flags.make
RULE/CMakeFiles/RULE.dir/src/Game.cpp.o: /home/pc/CLionProjects/OneCard/RULE/src/Game.cpp
RULE/CMakeFiles/RULE.dir/src/Game.cpp.o: RULE/CMakeFiles/RULE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pc/CLionProjects/OneCard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object RULE/CMakeFiles/RULE.dir/src/Game.cpp.o"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT RULE/CMakeFiles/RULE.dir/src/Game.cpp.o -MF CMakeFiles/RULE.dir/src/Game.cpp.o.d -o CMakeFiles/RULE.dir/src/Game.cpp.o -c /home/pc/CLionProjects/OneCard/RULE/src/Game.cpp

RULE/CMakeFiles/RULE.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RULE.dir/src/Game.cpp.i"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/CLionProjects/OneCard/RULE/src/Game.cpp > CMakeFiles/RULE.dir/src/Game.cpp.i

RULE/CMakeFiles/RULE.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RULE.dir/src/Game.cpp.s"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/CLionProjects/OneCard/RULE/src/Game.cpp -o CMakeFiles/RULE.dir/src/Game.cpp.s

RULE/CMakeFiles/RULE.dir/src/Player.cpp.o: RULE/CMakeFiles/RULE.dir/flags.make
RULE/CMakeFiles/RULE.dir/src/Player.cpp.o: /home/pc/CLionProjects/OneCard/RULE/src/Player.cpp
RULE/CMakeFiles/RULE.dir/src/Player.cpp.o: RULE/CMakeFiles/RULE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pc/CLionProjects/OneCard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object RULE/CMakeFiles/RULE.dir/src/Player.cpp.o"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT RULE/CMakeFiles/RULE.dir/src/Player.cpp.o -MF CMakeFiles/RULE.dir/src/Player.cpp.o.d -o CMakeFiles/RULE.dir/src/Player.cpp.o -c /home/pc/CLionProjects/OneCard/RULE/src/Player.cpp

RULE/CMakeFiles/RULE.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RULE.dir/src/Player.cpp.i"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/CLionProjects/OneCard/RULE/src/Player.cpp > CMakeFiles/RULE.dir/src/Player.cpp.i

RULE/CMakeFiles/RULE.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RULE.dir/src/Player.cpp.s"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/CLionProjects/OneCard/RULE/src/Player.cpp -o CMakeFiles/RULE.dir/src/Player.cpp.s

# Object files for target RULE
RULE_OBJECTS = \
"CMakeFiles/RULE.dir/src/Card.cpp.o" \
"CMakeFiles/RULE.dir/src/Deck.cpp.o" \
"CMakeFiles/RULE.dir/src/Game.cpp.o" \
"CMakeFiles/RULE.dir/src/Player.cpp.o"

# External object files for target RULE
RULE_EXTERNAL_OBJECTS =

RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/src/Card.cpp.o
RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/src/Deck.cpp.o
RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/src/Game.cpp.o
RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/src/Player.cpp.o
RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/build.make
RULE/libRULE.a: RULE/CMakeFiles/RULE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/pc/CLionProjects/OneCard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libRULE.a"
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && $(CMAKE_COMMAND) -P CMakeFiles/RULE.dir/cmake_clean_target.cmake
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RULE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
RULE/CMakeFiles/RULE.dir/build: RULE/libRULE.a
.PHONY : RULE/CMakeFiles/RULE.dir/build

RULE/CMakeFiles/RULE.dir/clean:
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE && $(CMAKE_COMMAND) -P CMakeFiles/RULE.dir/cmake_clean.cmake
.PHONY : RULE/CMakeFiles/RULE.dir/clean

RULE/CMakeFiles/RULE.dir/depend:
	cd /home/pc/CLionProjects/OneCard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pc/CLionProjects/OneCard /home/pc/CLionProjects/OneCard/RULE /home/pc/CLionProjects/OneCard/cmake-build-debug /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE /home/pc/CLionProjects/OneCard/cmake-build-debug/RULE/CMakeFiles/RULE.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : RULE/CMakeFiles/RULE.dir/depend

