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
CMAKE_COMMAND = /snap/clion/92/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/92/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /var/git/My-Game/Inventory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/git/My-Game/Inventory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Inventory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Inventory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Inventory.dir/flags.make

CMakeFiles/Inventory.dir/main.cpp.o: CMakeFiles/Inventory.dir/flags.make
CMakeFiles/Inventory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/git/My-Game/Inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Inventory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Inventory.dir/main.cpp.o -c /var/git/My-Game/Inventory/main.cpp

CMakeFiles/Inventory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inventory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/git/My-Game/Inventory/main.cpp > CMakeFiles/Inventory.dir/main.cpp.i

CMakeFiles/Inventory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inventory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/git/My-Game/Inventory/main.cpp -o CMakeFiles/Inventory.dir/main.cpp.s

# Object files for target Inventory
Inventory_OBJECTS = \
"CMakeFiles/Inventory.dir/main.cpp.o"

# External object files for target Inventory
Inventory_EXTERNAL_OBJECTS =

Inventory: CMakeFiles/Inventory.dir/main.cpp.o
Inventory: CMakeFiles/Inventory.dir/build.make
Inventory: CMakeFiles/Inventory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/git/My-Game/Inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Inventory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Inventory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Inventory.dir/build: Inventory

.PHONY : CMakeFiles/Inventory.dir/build

CMakeFiles/Inventory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Inventory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Inventory.dir/clean

CMakeFiles/Inventory.dir/depend:
	cd /var/git/My-Game/Inventory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/git/My-Game/Inventory /var/git/My-Game/Inventory /var/git/My-Game/Inventory/cmake-build-debug /var/git/My-Game/Inventory/cmake-build-debug /var/git/My-Game/Inventory/cmake-build-debug/CMakeFiles/Inventory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Inventory.dir/depend

