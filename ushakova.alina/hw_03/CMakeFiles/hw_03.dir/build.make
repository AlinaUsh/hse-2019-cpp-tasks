# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/osboxes/clion/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/osboxes/clion/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/osboxes/CLionProjects/hw_03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osboxes/CLionProjects/hw_03

# Include any dependencies generated for this target.
include CMakeFiles/hw_03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw_03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw_03.dir/flags.make

CMakeFiles/hw_03.dir/src/main.cpp.o: CMakeFiles/hw_03.dir/flags.make
CMakeFiles/hw_03.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/CLionProjects/hw_03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw_03.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_03.dir/src/main.cpp.o -c /home/osboxes/CLionProjects/hw_03/src/main.cpp

CMakeFiles/hw_03.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_03.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/CLionProjects/hw_03/src/main.cpp > CMakeFiles/hw_03.dir/src/main.cpp.i

CMakeFiles/hw_03.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_03.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/CLionProjects/hw_03/src/main.cpp -o CMakeFiles/hw_03.dir/src/main.cpp.s

CMakeFiles/hw_03.dir/src/CLI.cpp.o: CMakeFiles/hw_03.dir/flags.make
CMakeFiles/hw_03.dir/src/CLI.cpp.o: src/CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/CLionProjects/hw_03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw_03.dir/src/CLI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_03.dir/src/CLI.cpp.o -c /home/osboxes/CLionProjects/hw_03/src/CLI.cpp

CMakeFiles/hw_03.dir/src/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_03.dir/src/CLI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/CLionProjects/hw_03/src/CLI.cpp > CMakeFiles/hw_03.dir/src/CLI.cpp.i

CMakeFiles/hw_03.dir/src/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_03.dir/src/CLI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/CLionProjects/hw_03/src/CLI.cpp -o CMakeFiles/hw_03.dir/src/CLI.cpp.s

CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o: CMakeFiles/hw_03.dir/flags.make
CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o: src/HuffmanArchiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/CLionProjects/hw_03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o -c /home/osboxes/CLionProjects/hw_03/src/HuffmanArchiver.cpp

CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/CLionProjects/hw_03/src/HuffmanArchiver.cpp > CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.i

CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/CLionProjects/hw_03/src/HuffmanArchiver.cpp -o CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.s

CMakeFiles/hw_03.dir/src/Huffman.cpp.o: CMakeFiles/hw_03.dir/flags.make
CMakeFiles/hw_03.dir/src/Huffman.cpp.o: src/Huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/CLionProjects/hw_03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw_03.dir/src/Huffman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_03.dir/src/Huffman.cpp.o -c /home/osboxes/CLionProjects/hw_03/src/Huffman.cpp

CMakeFiles/hw_03.dir/src/Huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_03.dir/src/Huffman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/CLionProjects/hw_03/src/Huffman.cpp > CMakeFiles/hw_03.dir/src/Huffman.cpp.i

CMakeFiles/hw_03.dir/src/Huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_03.dir/src/Huffman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/CLionProjects/hw_03/src/Huffman.cpp -o CMakeFiles/hw_03.dir/src/Huffman.cpp.s

# Object files for target hw_03
hw_03_OBJECTS = \
"CMakeFiles/hw_03.dir/src/main.cpp.o" \
"CMakeFiles/hw_03.dir/src/CLI.cpp.o" \
"CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o" \
"CMakeFiles/hw_03.dir/src/Huffman.cpp.o"

# External object files for target hw_03
hw_03_EXTERNAL_OBJECTS =

hw_03: CMakeFiles/hw_03.dir/src/main.cpp.o
hw_03: CMakeFiles/hw_03.dir/src/CLI.cpp.o
hw_03: CMakeFiles/hw_03.dir/src/HuffmanArchiver.cpp.o
hw_03: CMakeFiles/hw_03.dir/src/Huffman.cpp.o
hw_03: CMakeFiles/hw_03.dir/build.make
hw_03: CMakeFiles/hw_03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/CLionProjects/hw_03/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable hw_03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw_03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw_03.dir/build: hw_03

.PHONY : CMakeFiles/hw_03.dir/build

CMakeFiles/hw_03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw_03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw_03.dir/clean

CMakeFiles/hw_03.dir/depend:
	cd /home/osboxes/CLionProjects/hw_03 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/CLionProjects/hw_03 /home/osboxes/CLionProjects/hw_03 /home/osboxes/CLionProjects/hw_03 /home/osboxes/CLionProjects/hw_03 /home/osboxes/CLionProjects/hw_03/CMakeFiles/hw_03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw_03.dir/depend

