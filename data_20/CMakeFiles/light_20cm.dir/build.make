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
CMAKE_SOURCE_DIR = /home/hxs/data_20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hxs/data_20

# Include any dependencies generated for this target.
include CMakeFiles/light_20cm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/light_20cm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/light_20cm.dir/flags.make

CMakeFiles/light_20cm.dir/videocapture.cpp.o: CMakeFiles/light_20cm.dir/flags.make
CMakeFiles/light_20cm.dir/videocapture.cpp.o: videocapture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hxs/data_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/light_20cm.dir/videocapture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/light_20cm.dir/videocapture.cpp.o -c /home/hxs/data_20/videocapture.cpp

CMakeFiles/light_20cm.dir/videocapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/light_20cm.dir/videocapture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hxs/data_20/videocapture.cpp > CMakeFiles/light_20cm.dir/videocapture.cpp.i

CMakeFiles/light_20cm.dir/videocapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/light_20cm.dir/videocapture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hxs/data_20/videocapture.cpp -o CMakeFiles/light_20cm.dir/videocapture.cpp.s

CMakeFiles/light_20cm.dir/videocapture.cpp.o.requires:

.PHONY : CMakeFiles/light_20cm.dir/videocapture.cpp.o.requires

CMakeFiles/light_20cm.dir/videocapture.cpp.o.provides: CMakeFiles/light_20cm.dir/videocapture.cpp.o.requires
	$(MAKE) -f CMakeFiles/light_20cm.dir/build.make CMakeFiles/light_20cm.dir/videocapture.cpp.o.provides.build
.PHONY : CMakeFiles/light_20cm.dir/videocapture.cpp.o.provides

CMakeFiles/light_20cm.dir/videocapture.cpp.o.provides.build: CMakeFiles/light_20cm.dir/videocapture.cpp.o


# Object files for target light_20cm
light_20cm_OBJECTS = \
"CMakeFiles/light_20cm.dir/videocapture.cpp.o"

# External object files for target light_20cm
light_20cm_EXTERNAL_OBJECTS =

light_20cm: CMakeFiles/light_20cm.dir/videocapture.cpp.o
light_20cm: CMakeFiles/light_20cm.dir/build.make
light_20cm: /usr/local/lib/libopencv_video.so.4.1.2
light_20cm: /usr/local/lib/libopencv_stitching.so.4.1.2
light_20cm: /usr/local/lib/libopencv_ml.so.4.1.2
light_20cm: /usr/local/lib/libopencv_gapi.so.4.1.2
light_20cm: /usr/local/lib/libopencv_photo.so.4.1.2
light_20cm: /usr/local/lib/libopencv_objdetect.so.4.1.2
light_20cm: /usr/local/lib/libopencv_highgui.so.4.1.2
light_20cm: /usr/local/lib/libopencv_dnn.so.4.1.2
light_20cm: /usr/local/lib/libopencv_calib3d.so.4.1.2
light_20cm: /usr/local/lib/libopencv_features2d.so.4.1.2
light_20cm: /usr/local/lib/libopencv_flann.so.4.1.2
light_20cm: /usr/local/lib/libopencv_videoio.so.4.1.2
light_20cm: /usr/local/lib/libopencv_imgcodecs.so.4.1.2
light_20cm: /usr/local/lib/libopencv_imgproc.so.4.1.2
light_20cm: /usr/local/lib/libopencv_core.so.4.1.2
light_20cm: CMakeFiles/light_20cm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hxs/data_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable light_20cm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/light_20cm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/light_20cm.dir/build: light_20cm

.PHONY : CMakeFiles/light_20cm.dir/build

CMakeFiles/light_20cm.dir/requires: CMakeFiles/light_20cm.dir/videocapture.cpp.o.requires

.PHONY : CMakeFiles/light_20cm.dir/requires

CMakeFiles/light_20cm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/light_20cm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/light_20cm.dir/clean

CMakeFiles/light_20cm.dir/depend:
	cd /home/hxs/data_20 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hxs/data_20 /home/hxs/data_20 /home/hxs/data_20 /home/hxs/data_20 /home/hxs/data_20/CMakeFiles/light_20cm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/light_20cm.dir/depend

