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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay"

# Include any dependencies generated for this target.
include CMakeFiles/vidDisplay.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vidDisplay.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vidDisplay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vidDisplay.dir/flags.make

CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o: CMakeFiles/vidDisplay.dir/flags.make
CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o: vidDisplay.cpp
CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o: CMakeFiles/vidDisplay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o -MF CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o.d -o CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o -c "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/vidDisplay.cpp"

CMakeFiles/vidDisplay.dir/vidDisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vidDisplay.dir/vidDisplay.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/vidDisplay.cpp" > CMakeFiles/vidDisplay.dir/vidDisplay.cpp.i

CMakeFiles/vidDisplay.dir/vidDisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vidDisplay.dir/vidDisplay.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/vidDisplay.cpp" -o CMakeFiles/vidDisplay.dir/vidDisplay.cpp.s

CMakeFiles/vidDisplay.dir/filter.cpp.o: CMakeFiles/vidDisplay.dir/flags.make
CMakeFiles/vidDisplay.dir/filter.cpp.o: filter.cpp
CMakeFiles/vidDisplay.dir/filter.cpp.o: CMakeFiles/vidDisplay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vidDisplay.dir/filter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vidDisplay.dir/filter.cpp.o -MF CMakeFiles/vidDisplay.dir/filter.cpp.o.d -o CMakeFiles/vidDisplay.dir/filter.cpp.o -c "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/filter.cpp"

CMakeFiles/vidDisplay.dir/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vidDisplay.dir/filter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/filter.cpp" > CMakeFiles/vidDisplay.dir/filter.cpp.i

CMakeFiles/vidDisplay.dir/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vidDisplay.dir/filter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/filter.cpp" -o CMakeFiles/vidDisplay.dir/filter.cpp.s

# Object files for target vidDisplay
vidDisplay_OBJECTS = \
"CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o" \
"CMakeFiles/vidDisplay.dir/filter.cpp.o"

# External object files for target vidDisplay
vidDisplay_EXTERNAL_OBJECTS =

vidDisplay: CMakeFiles/vidDisplay.dir/vidDisplay.cpp.o
vidDisplay: CMakeFiles/vidDisplay.dir/filter.cpp.o
vidDisplay: CMakeFiles/vidDisplay.dir/build.make
vidDisplay: /usr/local/lib/libopencv_gapi.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_stitching.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_alphamat.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_aruco.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_barcode.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_bgsegm.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_bioinspired.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_ccalib.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_dnn_objdetect.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_dnn_superres.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_dpm.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_face.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_freetype.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_fuzzy.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_hfs.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_img_hash.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_intensity_transform.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_line_descriptor.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_mcc.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_quality.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_rapid.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_reg.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_rgbd.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_saliency.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_sfm.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_stereo.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_structured_light.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_superres.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_surface_matching.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_tracking.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_videostab.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_viz.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_wechat_qrcode.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_xfeatures2d.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_xobjdetect.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_xphoto.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_shape.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_highgui.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_datasets.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_plot.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_text.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_ml.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_phase_unwrapping.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_optflow.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_ximgproc.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_video.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_videoio.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_imgcodecs.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_objdetect.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_calib3d.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_dnn.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_features2d.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_flann.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_photo.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_imgproc.4.7.0.dylib
vidDisplay: /usr/local/lib/libopencv_core.4.7.0.dylib
vidDisplay: CMakeFiles/vidDisplay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable vidDisplay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vidDisplay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vidDisplay.dir/build: vidDisplay
.PHONY : CMakeFiles/vidDisplay.dir/build

CMakeFiles/vidDisplay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vidDisplay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vidDisplay.dir/clean

CMakeFiles/vidDisplay.dir/depend:
	cd "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay" "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay" "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay" "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay" "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/CMakeFiles/vidDisplay.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/vidDisplay.dir/depend

