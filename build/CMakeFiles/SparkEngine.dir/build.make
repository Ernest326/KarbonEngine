# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ernest\Documents\SparkEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ernest\Documents\SparkEngine\build

# Include any dependencies generated for this target.
include CMakeFiles/SparkEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SparkEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SparkEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SparkEngine.dir/flags.make

CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj: CMakeFiles/SparkEngine.dir/flags.make
CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj: CMakeFiles/SparkEngine.dir/includes_CXX.rsp
CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj: C:/Users/Ernest/Documents/SparkEngine/src/App/app.cpp
CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj: CMakeFiles/SparkEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj -MF CMakeFiles\SparkEngine.dir\src\App\app.cpp.obj.d -o CMakeFiles\SparkEngine.dir\src\App\app.cpp.obj -c C:\Users\Ernest\Documents\SparkEngine\src\App\app.cpp

CMakeFiles/SparkEngine.dir/src/App/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SparkEngine.dir/src/App/app.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\SparkEngine\src\App\app.cpp > CMakeFiles\SparkEngine.dir\src\App\app.cpp.i

CMakeFiles/SparkEngine.dir/src/App/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SparkEngine.dir/src/App/app.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\SparkEngine\src\App\app.cpp -o CMakeFiles\SparkEngine.dir\src\App\app.cpp.s

CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj: CMakeFiles/SparkEngine.dir/flags.make
CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj: CMakeFiles/SparkEngine.dir/includes_CXX.rsp
CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj: C:/Users/Ernest/Documents/SparkEngine/src/App/window.cpp
CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj: CMakeFiles/SparkEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj -MF CMakeFiles\SparkEngine.dir\src\App\window.cpp.obj.d -o CMakeFiles\SparkEngine.dir\src\App\window.cpp.obj -c C:\Users\Ernest\Documents\SparkEngine\src\App\window.cpp

CMakeFiles/SparkEngine.dir/src/App/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SparkEngine.dir/src/App/window.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\SparkEngine\src\App\window.cpp > CMakeFiles\SparkEngine.dir\src\App\window.cpp.i

CMakeFiles/SparkEngine.dir/src/App/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SparkEngine.dir/src/App/window.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\SparkEngine\src\App\window.cpp -o CMakeFiles\SparkEngine.dir\src\App\window.cpp.s

CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj: CMakeFiles/SparkEngine.dir/flags.make
CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj: CMakeFiles/SparkEngine.dir/includes_CXX.rsp
CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj: C:/Users/Ernest/Documents/SparkEngine/src/Core/pipeline.cpp
CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj: CMakeFiles/SparkEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj -MF CMakeFiles\SparkEngine.dir\src\Core\pipeline.cpp.obj.d -o CMakeFiles\SparkEngine.dir\src\Core\pipeline.cpp.obj -c C:\Users\Ernest\Documents\SparkEngine\src\Core\pipeline.cpp

CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\SparkEngine\src\Core\pipeline.cpp > CMakeFiles\SparkEngine.dir\src\Core\pipeline.cpp.i

CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\SparkEngine\src\Core\pipeline.cpp -o CMakeFiles\SparkEngine.dir\src\Core\pipeline.cpp.s

CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj: CMakeFiles/SparkEngine.dir/flags.make
CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj: CMakeFiles/SparkEngine.dir/includes_CXX.rsp
CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj: C:/Users/Ernest/Documents/SparkEngine/src/Core/spark_device.cpp
CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj: CMakeFiles/SparkEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj -MF CMakeFiles\SparkEngine.dir\src\Core\spark_device.cpp.obj.d -o CMakeFiles\SparkEngine.dir\src\Core\spark_device.cpp.obj -c C:\Users\Ernest\Documents\SparkEngine\src\Core\spark_device.cpp

CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\SparkEngine\src\Core\spark_device.cpp > CMakeFiles\SparkEngine.dir\src\Core\spark_device.cpp.i

CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\SparkEngine\src\Core\spark_device.cpp -o CMakeFiles\SparkEngine.dir\src\Core\spark_device.cpp.s

CMakeFiles/SparkEngine.dir/src/main.cpp.obj: CMakeFiles/SparkEngine.dir/flags.make
CMakeFiles/SparkEngine.dir/src/main.cpp.obj: CMakeFiles/SparkEngine.dir/includes_CXX.rsp
CMakeFiles/SparkEngine.dir/src/main.cpp.obj: C:/Users/Ernest/Documents/SparkEngine/src/main.cpp
CMakeFiles/SparkEngine.dir/src/main.cpp.obj: CMakeFiles/SparkEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SparkEngine.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SparkEngine.dir/src/main.cpp.obj -MF CMakeFiles\SparkEngine.dir\src\main.cpp.obj.d -o CMakeFiles\SparkEngine.dir\src\main.cpp.obj -c C:\Users\Ernest\Documents\SparkEngine\src\main.cpp

CMakeFiles/SparkEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SparkEngine.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\SparkEngine\src\main.cpp > CMakeFiles\SparkEngine.dir\src\main.cpp.i

CMakeFiles/SparkEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SparkEngine.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\SparkEngine\src\main.cpp -o CMakeFiles\SparkEngine.dir\src\main.cpp.s

# Object files for target SparkEngine
SparkEngine_OBJECTS = \
"CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj" \
"CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj" \
"CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj" \
"CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj" \
"CMakeFiles/SparkEngine.dir/src/main.cpp.obj"

# External object files for target SparkEngine
SparkEngine_EXTERNAL_OBJECTS =

SparkEngine.exe: CMakeFiles/SparkEngine.dir/src/App/app.cpp.obj
SparkEngine.exe: CMakeFiles/SparkEngine.dir/src/App/window.cpp.obj
SparkEngine.exe: CMakeFiles/SparkEngine.dir/src/Core/pipeline.cpp.obj
SparkEngine.exe: CMakeFiles/SparkEngine.dir/src/Core/spark_device.cpp.obj
SparkEngine.exe: CMakeFiles/SparkEngine.dir/src/main.cpp.obj
SparkEngine.exe: CMakeFiles/SparkEngine.dir/build.make
SparkEngine.exe: CMakeFiles/SparkEngine.dir/linkLibs.rsp
SparkEngine.exe: CMakeFiles/SparkEngine.dir/objects1.rsp
SparkEngine.exe: CMakeFiles/SparkEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SparkEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SparkEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SparkEngine.dir/build: SparkEngine.exe
.PHONY : CMakeFiles/SparkEngine.dir/build

CMakeFiles/SparkEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SparkEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SparkEngine.dir/clean

CMakeFiles/SparkEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ernest\Documents\SparkEngine C:\Users\Ernest\Documents\SparkEngine C:\Users\Ernest\Documents\SparkEngine\build C:\Users\Ernest\Documents\SparkEngine\build C:\Users\Ernest\Documents\SparkEngine\build\CMakeFiles\SparkEngine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SparkEngine.dir/depend

