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
include CMakeFiles/opencv_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_example.dir/flags.make

CMakeFiles/opencv_example.dir/videocapture.cpp.o: CMakeFiles/opencv_example.dir/flags.make
CMakeFiles/opencv_example.dir/videocapture.cpp.o: videocapture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hxs/code_backup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_example.dir/videocapture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_example.dir/videocapture.cpp.o -c /home/hxs/code_backup/videocapture.cpp

CMakeFiles/opencv_example.dir/videocapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_example.dir/videocapture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hxs/code_backup/videocapture.cpp > CMakeFiles/opencv_example.dir/videocapture.cpp.i

CMakeFiles/opencv_example.dir/videocapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_example.dir/videocapture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hxs/code_backup/videocapture.cpp -o CMakeFiles/opencv_example.dir/videocapture.cpp.s

CMakeFiles/opencv_example.dir/videocapture.cpp.o.requires:

.PHONY : CMakeFiles/opencv_example.dir/videocapture.cpp.o.requires

CMakeFiles/opencv_example.dir/videocapture.cpp.o.provides: CMakeFiles/opencv_example.dir/videocapture.cpp.o.requires
	$(MAKE) -f CMakeFiles/opencv_example.dir/build.make CMakeFiles/opencv_example.dir/videocapture.cpp.o.provides.build
.PHONY : CMakeFiles/opencv_example.dir/videocapture.cpp.o.provides

CMakeFiles/opencv_example.dir/videocapture.cpp.o.provides.build: CMakeFiles/opencv_example.dir/videocapture.cpp.o


# Object files for target opencv_example
opencv_example_OBJECTS = \
"CMakeFiles/opencv_example.dir/videocapture.cpp.o"

# External object files for target opencv_example
opencv_example_EXTERNAL_OBJECTS =

opencv_example: CMakeFiles/opencv_example.dir/videocapture.cpp.o
opencv_example: CMakeFiles/opencv_example.dir/build.make
opencv_example: /usr/local/lib/libopencv_video.so.4.1.2
opencv_example: /usr/local/lib/libopencv_stitching.so.4.1.2
opencv_example: /usr/local/lib/libopencv_ml.so.4.1.2
opencv_example: /usr/local/lib/libopencv_gapi.so.4.1.2
opencv_example: /usr/local/lib/libopencv_photo.so.4.1.2
opencv_example: /usr/local/lib/libopencv_objdetect.so.4.1.2
opencv_example: /usr/local/lib/libopencv_highgui.so.4.1.2
opencv_example: /usr/local/lib/libopencv_dnn.so.4.1.2
opencv_example: /usr/local/lib/libopencv_calib3d.so.4.1.2
opencv_example: /usr/local/lib/libopencv_features2d.so.4.1.2
opencv_example: /usr/local/lib/libopencv_flann.so.4.1.2
opencv_example: /usr/local/lib/libopencv_videoio.so.4.1.2
opencv_example: /usr/local/lib/libopencv_imgcodecs.so.4.1.2
opencv_example: /usr/local/lib/libopencv_imgproc.so.4.1.2
opencv_example: /usr/local/lib/libopencv_core.so.4.1.2
opencv_example: CMakeFiles/opencv_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hxs/code_backup/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_example.dir/build: opencv_example

.PHONY : CMakeFiles/opencv_example.dir/build

CMakeFiles/opencv_example.dir/requires: CMakeFiles/opencv_example.dir/videocapture.cpp.o.requires

.PHONY : CMakeFiles/opencv_example.dir/requires

CMakeFiles/opencv_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_example.dir/clean

CMakeFiles/opencv_example.dir/depend:
	cd /home/hxs/code_backup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup /home/hxs/code_backup/CMakeFiles/opencv_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_example.dir/depend

