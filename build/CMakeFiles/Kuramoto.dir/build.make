# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haakolau/Projects/Master/Kuramoto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haakolau/Projects/Master/Kuramoto/build

# Include any dependencies generated for this target.
include CMakeFiles/Kuramoto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Kuramoto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Kuramoto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kuramoto.dir/flags.make

CMakeFiles/Kuramoto.dir/src/main.cpp.o: CMakeFiles/Kuramoto.dir/flags.make
CMakeFiles/Kuramoto.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Kuramoto.dir/src/main.cpp.o: CMakeFiles/Kuramoto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haakolau/Projects/Master/Kuramoto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kuramoto.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kuramoto.dir/src/main.cpp.o -MF CMakeFiles/Kuramoto.dir/src/main.cpp.o.d -o CMakeFiles/Kuramoto.dir/src/main.cpp.o -c /home/haakolau/Projects/Master/Kuramoto/src/main.cpp

CMakeFiles/Kuramoto.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kuramoto.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haakolau/Projects/Master/Kuramoto/src/main.cpp > CMakeFiles/Kuramoto.dir/src/main.cpp.i

CMakeFiles/Kuramoto.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kuramoto.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haakolau/Projects/Master/Kuramoto/src/main.cpp -o CMakeFiles/Kuramoto.dir/src/main.cpp.s

CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o: CMakeFiles/Kuramoto.dir/flags.make
CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o: ../src/Oscillator.cpp
CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o: CMakeFiles/Kuramoto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haakolau/Projects/Master/Kuramoto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o -MF CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o.d -o CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o -c /home/haakolau/Projects/Master/Kuramoto/src/Oscillator.cpp

CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haakolau/Projects/Master/Kuramoto/src/Oscillator.cpp > CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.i

CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haakolau/Projects/Master/Kuramoto/src/Oscillator.cpp -o CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.s

CMakeFiles/Kuramoto.dir/src/Grid.cpp.o: CMakeFiles/Kuramoto.dir/flags.make
CMakeFiles/Kuramoto.dir/src/Grid.cpp.o: ../src/Grid.cpp
CMakeFiles/Kuramoto.dir/src/Grid.cpp.o: CMakeFiles/Kuramoto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haakolau/Projects/Master/Kuramoto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Kuramoto.dir/src/Grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kuramoto.dir/src/Grid.cpp.o -MF CMakeFiles/Kuramoto.dir/src/Grid.cpp.o.d -o CMakeFiles/Kuramoto.dir/src/Grid.cpp.o -c /home/haakolau/Projects/Master/Kuramoto/src/Grid.cpp

CMakeFiles/Kuramoto.dir/src/Grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kuramoto.dir/src/Grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haakolau/Projects/Master/Kuramoto/src/Grid.cpp > CMakeFiles/Kuramoto.dir/src/Grid.cpp.i

CMakeFiles/Kuramoto.dir/src/Grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kuramoto.dir/src/Grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haakolau/Projects/Master/Kuramoto/src/Grid.cpp -o CMakeFiles/Kuramoto.dir/src/Grid.cpp.s

# Object files for target Kuramoto
Kuramoto_OBJECTS = \
"CMakeFiles/Kuramoto.dir/src/main.cpp.o" \
"CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o" \
"CMakeFiles/Kuramoto.dir/src/Grid.cpp.o"

# External object files for target Kuramoto
Kuramoto_EXTERNAL_OBJECTS =

Kuramoto: CMakeFiles/Kuramoto.dir/src/main.cpp.o
Kuramoto: CMakeFiles/Kuramoto.dir/src/Oscillator.cpp.o
Kuramoto: CMakeFiles/Kuramoto.dir/src/Grid.cpp.o
Kuramoto: CMakeFiles/Kuramoto.dir/build.make
Kuramoto: /usr/local/lib/libsfml-graphics.so.2.6.0
Kuramoto: /usr/local/lib/libsfml-audio.so.2.6.0
Kuramoto: /usr/local/lib/libsfml-window.so.2.6.0
Kuramoto: /usr/local/lib/libsfml-system.so.2.6.0
Kuramoto: CMakeFiles/Kuramoto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haakolau/Projects/Master/Kuramoto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Kuramoto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Kuramoto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kuramoto.dir/build: Kuramoto
.PHONY : CMakeFiles/Kuramoto.dir/build

CMakeFiles/Kuramoto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Kuramoto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Kuramoto.dir/clean

CMakeFiles/Kuramoto.dir/depend:
	cd /home/haakolau/Projects/Master/Kuramoto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haakolau/Projects/Master/Kuramoto /home/haakolau/Projects/Master/Kuramoto /home/haakolau/Projects/Master/Kuramoto/build /home/haakolau/Projects/Master/Kuramoto/build /home/haakolau/Projects/Master/Kuramoto/build/CMakeFiles/Kuramoto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kuramoto.dir/depend

