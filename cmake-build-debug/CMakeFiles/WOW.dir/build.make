# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\ClionProjects\WOW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\ClionProjects\WOW\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WOW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WOW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WOW.dir/flags.make

CMakeFiles/WOW.dir/main.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WOW.dir/main.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\main.cpp.obj -c D:\Documents\ClionProjects\WOW\main.cpp

CMakeFiles/WOW.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/main.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\main.cpp > CMakeFiles\WOW.dir\main.cpp.i

CMakeFiles/WOW.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/main.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\main.cpp -o CMakeFiles\WOW.dir\main.cpp.s

CMakeFiles/WOW.dir/src/HeadQuarter.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/src/HeadQuarter.cpp.obj: ../src/HeadQuarter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WOW.dir/src/HeadQuarter.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\src\HeadQuarter.cpp.obj -c D:\Documents\ClionProjects\WOW\src\HeadQuarter.cpp

CMakeFiles/WOW.dir/src/HeadQuarter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/src/HeadQuarter.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\src\HeadQuarter.cpp > CMakeFiles\WOW.dir\src\HeadQuarter.cpp.i

CMakeFiles/WOW.dir/src/HeadQuarter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/src/HeadQuarter.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\src\HeadQuarter.cpp -o CMakeFiles\WOW.dir\src\HeadQuarter.cpp.s

CMakeFiles/WOW.dir/src/Soldier.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/src/Soldier.cpp.obj: ../src/Soldier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WOW.dir/src/Soldier.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\src\Soldier.cpp.obj -c D:\Documents\ClionProjects\WOW\src\Soldier.cpp

CMakeFiles/WOW.dir/src/Soldier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/src/Soldier.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\src\Soldier.cpp > CMakeFiles\WOW.dir\src\Soldier.cpp.i

CMakeFiles/WOW.dir/src/Soldier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/src/Soldier.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\src\Soldier.cpp -o CMakeFiles\WOW.dir\src\Soldier.cpp.s

CMakeFiles/WOW.dir/src/Weapon.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/src/Weapon.cpp.obj: ../src/Weapon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WOW.dir/src/Weapon.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\src\Weapon.cpp.obj -c D:\Documents\ClionProjects\WOW\src\Weapon.cpp

CMakeFiles/WOW.dir/src/Weapon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/src/Weapon.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\src\Weapon.cpp > CMakeFiles\WOW.dir\src\Weapon.cpp.i

CMakeFiles/WOW.dir/src/Weapon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/src/Weapon.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\src\Weapon.cpp -o CMakeFiles\WOW.dir\src\Weapon.cpp.s

CMakeFiles/WOW.dir/src/City.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/src/City.cpp.obj: ../src/City.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WOW.dir/src/City.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\src\City.cpp.obj -c D:\Documents\ClionProjects\WOW\src\City.cpp

CMakeFiles/WOW.dir/src/City.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/src/City.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\src\City.cpp > CMakeFiles\WOW.dir\src\City.cpp.i

CMakeFiles/WOW.dir/src/City.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/src/City.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\src\City.cpp -o CMakeFiles\WOW.dir\src\City.cpp.s

CMakeFiles/WOW.dir/test.cpp.obj: CMakeFiles/WOW.dir/flags.make
CMakeFiles/WOW.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WOW.dir/test.cpp.obj"
	D:\Documents\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WOW.dir\test.cpp.obj -c D:\Documents\ClionProjects\WOW\test.cpp

CMakeFiles/WOW.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WOW.dir/test.cpp.i"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\ClionProjects\WOW\test.cpp > CMakeFiles\WOW.dir\test.cpp.i

CMakeFiles/WOW.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WOW.dir/test.cpp.s"
	D:\Documents\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\ClionProjects\WOW\test.cpp -o CMakeFiles\WOW.dir\test.cpp.s

# Object files for target WOW
WOW_OBJECTS = \
"CMakeFiles/WOW.dir/main.cpp.obj" \
"CMakeFiles/WOW.dir/src/HeadQuarter.cpp.obj" \
"CMakeFiles/WOW.dir/src/Soldier.cpp.obj" \
"CMakeFiles/WOW.dir/src/Weapon.cpp.obj" \
"CMakeFiles/WOW.dir/src/City.cpp.obj" \
"CMakeFiles/WOW.dir/test.cpp.obj"

# External object files for target WOW
WOW_EXTERNAL_OBJECTS =

WOW.exe: CMakeFiles/WOW.dir/main.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/src/HeadQuarter.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/src/Soldier.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/src/Weapon.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/src/City.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/test.cpp.obj
WOW.exe: CMakeFiles/WOW.dir/build.make
WOW.exe: CMakeFiles/WOW.dir/linklibs.rsp
WOW.exe: CMakeFiles/WOW.dir/objects1.rsp
WOW.exe: CMakeFiles/WOW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable WOW.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WOW.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WOW.dir/build: WOW.exe

.PHONY : CMakeFiles/WOW.dir/build

CMakeFiles/WOW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WOW.dir\cmake_clean.cmake
.PHONY : CMakeFiles/WOW.dir/clean

CMakeFiles/WOW.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\ClionProjects\WOW D:\Documents\ClionProjects\WOW D:\Documents\ClionProjects\WOW\cmake-build-debug D:\Documents\ClionProjects\WOW\cmake-build-debug D:\Documents\ClionProjects\WOW\cmake-build-debug\CMakeFiles\WOW.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WOW.dir/depend

