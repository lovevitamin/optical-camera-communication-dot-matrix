# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/hxs/code_backup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hxs/code_backup

# Include any dependencies generated for this target.
include CMakeFiles/largest_com.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/largest_com.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/largest_com.dir/flags.make

CMakeFiles/largest_com.dir/largest_com.cpp.o: CMakeFiles/largest_com.dir/flags.make
CMakeFiles/largest_com.dir/largest_com.cpp.o: largest_com.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hxs/code_backup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/largest_com.dir/largest_com.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/largest_com.dir/largest_com.cpp.o -c /home/hxs/code_backup/largest_com.cpp

CMakeFiles/largest_com.dir/largest_com.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/largest_com.dir/largest_com.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hxs/code_backup/largest_com.cpp > CMakeFiles/largest_com.dir/largest_com.cpp.i

CMakeFiles/largest_com.dir/largest_com.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/largest_com.dir/largest_com.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hxs/code_backup/largest_com.cpp -o CMakeFiles/largest_com.dir/largest_com.cpp.s

CMakeFiles/largest_com.dir/largest_com.cpp.o.requires:

.PHONY : CMakeFiles/largest_com.dir/largest_com.cpp.o.requires

CMakeFiles/largest_com.dir/largest_com.cpp.o.provides: CMakeFiles/largest_com.dir/largest_com.cpp.o.requires
	$(MAKE) -f CMakeFiles/largest_com.dir/build.make CMakeFiles/largest_com.dir/largest_com.cpp.o.provides.build
.PHONY : CMakeFiles/largest_com.dir/largest_com.cpp.o.provides

CMakeFiles/largest_com.dir/largest_com.cpp.o.provides.build: CMakeFiles/largest_com.dir/largest_com.cpp.o


# Object files for target largest_com
largest_com_OBJECTS = \
"CMakeFiles/largest_com.dir/largest_com.cpp.o"

# External object files for target largest_com
largest_com_EXTERNAL_OBJECTS =

largest_com: CMakeFiles/largest_com.dir/largest_com.cpp.o
largest_com: CMakeFiles/largest_com.dir/build.make
largest_com: /usr/local/lib/libopencv_video.so.4.1.2
largest_com: /usr/local/lib/libopencv_stitching.so.4.1.2
largest_com: /usr/local/lib/libopencv_ml.so.4.1.2
largest_com: /usr/local/lib/libopencv_gapi.so.4.1.2
largest_com: /usr/local/lib/libopencv_photo.so.4.1.2
largest_com: /usr/local/lib/libopencv_objdetect.so.4.1.2
largest_com: /usr/local/lib/libopencv_highgui.so.4.1.2
largest_com: /usr/local/lib/libopencv_dnn.so.4.1.2
largest_com: /usr/local/lib/libopencv_calib3d.so.4.1.2
largest_com: /usr/local/lib/libopencv_features2d.so.4.1.2
largest_com: /usr/local/lib/libopencv_flann.so.4.1.2
largest_com: /usr/local/lib/libopencv_videoio.so.4.1.2
largest_com: /usr/local/lib/libopencv_imgcodecs.so.4.1.2
largest_com: /usr/local/lib/libopencv_imgproc.so.4.1.2
largest_com: /usr/local/lib/libopencv_core.so.4.1.2
largest_com: CMakeFiles/largest_com.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hxs/code_backup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable largest_com"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/largest_com.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/largest_com.dir/build: largest_com

.PHONY : CMakeFiles/largest_com.dir/build

CMakeFiles/largest_com.dir/requires: CMakeFiles/largest_com.dir/largest_com.cpp.o.requires

.PHONY : CMakeFiles/largest_com.dir/requires

CMakeFiles/largest_com.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/largest_com.dir/cmake_clean.cmake
.PHONY : CMakeFiles/largest_com.dir/clean

CMakeFiles/largest_com.dir/depend:
	cd /home/hxs/code_backup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup/CMakeFiles/largest_com.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/largest_com.dir/depend
