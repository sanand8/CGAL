# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/devil/Desktop/CGAL/CGAL_3_B170305CS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devil/Desktop/CGAL/CGAL_3_B170305CS

# Include any dependencies generated for this target.
include CMakeFiles/CGAL_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CGAL_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CGAL_3.dir/flags.make

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o: CMakeFiles/CGAL_3.dir/flags.make
CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o: CGAL_3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devil/Desktop/CGAL/CGAL_3_B170305CS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o -c /home/devil/Desktop/CGAL/CGAL_3_B170305CS/CGAL_3.cpp

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGAL_3.dir/CGAL_3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devil/Desktop/CGAL/CGAL_3_B170305CS/CGAL_3.cpp > CMakeFiles/CGAL_3.dir/CGAL_3.cpp.i

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGAL_3.dir/CGAL_3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devil/Desktop/CGAL/CGAL_3_B170305CS/CGAL_3.cpp -o CMakeFiles/CGAL_3.dir/CGAL_3.cpp.s

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.requires:

.PHONY : CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.requires

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.provides: CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGAL_3.dir/build.make CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.provides.build
.PHONY : CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.provides

CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.provides.build: CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o


# Object files for target CGAL_3
CGAL_3_OBJECTS = \
"CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o"

# External object files for target CGAL_3
CGAL_3_EXTERNAL_OBJECTS =

CGAL_3: CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o
CGAL_3: CMakeFiles/CGAL_3.dir/build.make
CGAL_3: /usr/lib/x86_64-linux-gnu/libmpfr.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libgmpxx.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libgmp.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libCGAL_Qt5.so.13.0.1
CGAL_3: /usr/lib/x86_64-linux-gnu/libCGAL.so.13.0.1
CGAL_3: /usr/lib/x86_64-linux-gnu/libGLU.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libGL.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Script.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libCGAL_Qt5.so.13.0.1
CGAL_3: /usr/lib/x86_64-linux-gnu/libCGAL.so.13.0.1
CGAL_3: /usr/lib/x86_64-linux-gnu/libGLU.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libGL.so
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
CGAL_3: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
CGAL_3: CMakeFiles/CGAL_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devil/Desktop/CGAL/CGAL_3_B170305CS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CGAL_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CGAL_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CGAL_3.dir/build: CGAL_3

.PHONY : CMakeFiles/CGAL_3.dir/build

CMakeFiles/CGAL_3.dir/requires: CMakeFiles/CGAL_3.dir/CGAL_3.cpp.o.requires

.PHONY : CMakeFiles/CGAL_3.dir/requires

CMakeFiles/CGAL_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CGAL_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CGAL_3.dir/clean

CMakeFiles/CGAL_3.dir/depend:
	cd /home/devil/Desktop/CGAL/CGAL_3_B170305CS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devil/Desktop/CGAL/CGAL_3_B170305CS /home/devil/Desktop/CGAL/CGAL_3_B170305CS /home/devil/Desktop/CGAL/CGAL_3_B170305CS /home/devil/Desktop/CGAL/CGAL_3_B170305CS /home/devil/Desktop/CGAL/CGAL_3_B170305CS/CMakeFiles/CGAL_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CGAL_3.dir/depend

