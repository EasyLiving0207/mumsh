# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/easyliving/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/easyliving/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/easyliving/Desktop/Files/FA2020/VE482/p1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1.dir/flags.make

CMakeFiles/p1.dir/main.c.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/p1.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p1.dir/main.c.o   -c /Users/easyliving/Desktop/Files/FA2020/VE482/p1/main.c

CMakeFiles/p1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p1.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/easyliving/Desktop/Files/FA2020/VE482/p1/main.c > CMakeFiles/p1.dir/main.c.i

CMakeFiles/p1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p1.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/easyliving/Desktop/Files/FA2020/VE482/p1/main.c -o CMakeFiles/p1.dir/main.c.s

CMakeFiles/p1.dir/parse.c.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/parse.c.o: ../parse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/p1.dir/parse.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p1.dir/parse.c.o   -c /Users/easyliving/Desktop/Files/FA2020/VE482/p1/parse.c

CMakeFiles/p1.dir/parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p1.dir/parse.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/easyliving/Desktop/Files/FA2020/VE482/p1/parse.c > CMakeFiles/p1.dir/parse.c.i

CMakeFiles/p1.dir/parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p1.dir/parse.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/easyliving/Desktop/Files/FA2020/VE482/p1/parse.c -o CMakeFiles/p1.dir/parse.c.s

CMakeFiles/p1.dir/built_in.c.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/built_in.c.o: ../built_in.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/p1.dir/built_in.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p1.dir/built_in.c.o   -c /Users/easyliving/Desktop/Files/FA2020/VE482/p1/built_in.c

CMakeFiles/p1.dir/built_in.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p1.dir/built_in.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/easyliving/Desktop/Files/FA2020/VE482/p1/built_in.c > CMakeFiles/p1.dir/built_in.c.i

CMakeFiles/p1.dir/built_in.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p1.dir/built_in.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/easyliving/Desktop/Files/FA2020/VE482/p1/built_in.c -o CMakeFiles/p1.dir/built_in.c.s

CMakeFiles/p1.dir/execute.c.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/execute.c.o: ../execute.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/p1.dir/execute.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p1.dir/execute.c.o   -c /Users/easyliving/Desktop/Files/FA2020/VE482/p1/execute.c

CMakeFiles/p1.dir/execute.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p1.dir/execute.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/easyliving/Desktop/Files/FA2020/VE482/p1/execute.c > CMakeFiles/p1.dir/execute.c.i

CMakeFiles/p1.dir/execute.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p1.dir/execute.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/easyliving/Desktop/Files/FA2020/VE482/p1/execute.c -o CMakeFiles/p1.dir/execute.c.s

# Object files for target p1
p1_OBJECTS = \
"CMakeFiles/p1.dir/main.c.o" \
"CMakeFiles/p1.dir/parse.c.o" \
"CMakeFiles/p1.dir/built_in.c.o" \
"CMakeFiles/p1.dir/execute.c.o"

# External object files for target p1
p1_EXTERNAL_OBJECTS =

p1: CMakeFiles/p1.dir/main.c.o
p1: CMakeFiles/p1.dir/parse.c.o
p1: CMakeFiles/p1.dir/built_in.c.o
p1: CMakeFiles/p1.dir/execute.c.o
p1: CMakeFiles/p1.dir/build.make
p1: CMakeFiles/p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable p1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1.dir/build: p1

.PHONY : CMakeFiles/p1.dir/build

CMakeFiles/p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1.dir/clean

CMakeFiles/p1.dir/depend:
	cd /Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/easyliving/Desktop/Files/FA2020/VE482/p1 /Users/easyliving/Desktop/Files/FA2020/VE482/p1 /Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug /Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug /Users/easyliving/Desktop/Files/FA2020/VE482/p1/cmake-build-debug/CMakeFiles/p1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1.dir/depend

