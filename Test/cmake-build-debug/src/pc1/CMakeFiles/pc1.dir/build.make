# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/fuookami/文档/ProgramFile/Clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/fuookami/文档/ProgramFile/Clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug

# Include any dependencies generated for this target.
include src/pc1/CMakeFiles/pc1.dir/depend.make

# Include the progress variables for this target.
include src/pc1/CMakeFiles/pc1.dir/progress.make

# Include the compile flags for this target's objects.
include src/pc1/CMakeFiles/pc1.dir/flags.make

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o: src/pc1/CMakeFiles/pc1.dir/flags.make
src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o: ../src/SafePthreadExtra/SafePthreadExtra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o -c /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/SafePthreadExtra/SafePthreadExtra.cpp

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.i"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/SafePthreadExtra/SafePthreadExtra.cpp > CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.i

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.s"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/SafePthreadExtra/SafePthreadExtra.cpp -o CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.s

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.requires:

.PHONY : src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.requires

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.provides: src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.requires
	$(MAKE) -f src/pc1/CMakeFiles/pc1.dir/build.make src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.provides.build
.PHONY : src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.provides

src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.provides.build: src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o


src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o: src/pc1/CMakeFiles/pc1.dir/flags.make
src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o: ../src/pc1/pc1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pc1.dir/pc1.cpp.o -c /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/pc1.cpp

src/pc1/CMakeFiles/pc1.dir/pc1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pc1.dir/pc1.cpp.i"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/pc1.cpp > CMakeFiles/pc1.dir/pc1.cpp.i

src/pc1/CMakeFiles/pc1.dir/pc1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pc1.dir/pc1.cpp.s"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/pc1.cpp -o CMakeFiles/pc1.dir/pc1.cpp.s

src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.requires:

.PHONY : src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.requires

src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.provides: src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.requires
	$(MAKE) -f src/pc1/CMakeFiles/pc1.dir/build.make src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.provides.build
.PHONY : src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.provides

src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.provides.build: src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o


src/pc1/CMakeFiles/pc1.dir/main.cpp.o: src/pc1/CMakeFiles/pc1.dir/flags.make
src/pc1/CMakeFiles/pc1.dir/main.cpp.o: ../src/pc1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/pc1/CMakeFiles/pc1.dir/main.cpp.o"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pc1.dir/main.cpp.o -c /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/main.cpp

src/pc1/CMakeFiles/pc1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pc1.dir/main.cpp.i"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/main.cpp > CMakeFiles/pc1.dir/main.cpp.i

src/pc1/CMakeFiles/pc1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pc1.dir/main.cpp.s"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && /usr/local/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1/main.cpp -o CMakeFiles/pc1.dir/main.cpp.s

src/pc1/CMakeFiles/pc1.dir/main.cpp.o.requires:

.PHONY : src/pc1/CMakeFiles/pc1.dir/main.cpp.o.requires

src/pc1/CMakeFiles/pc1.dir/main.cpp.o.provides: src/pc1/CMakeFiles/pc1.dir/main.cpp.o.requires
	$(MAKE) -f src/pc1/CMakeFiles/pc1.dir/build.make src/pc1/CMakeFiles/pc1.dir/main.cpp.o.provides.build
.PHONY : src/pc1/CMakeFiles/pc1.dir/main.cpp.o.provides

src/pc1/CMakeFiles/pc1.dir/main.cpp.o.provides.build: src/pc1/CMakeFiles/pc1.dir/main.cpp.o


# Object files for target pc1
pc1_OBJECTS = \
"CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o" \
"CMakeFiles/pc1.dir/pc1.cpp.o" \
"CMakeFiles/pc1.dir/main.cpp.o"

# External object files for target pc1
pc1_EXTERNAL_OBJECTS =

bin/pc1: src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o
bin/pc1: src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o
bin/pc1: src/pc1/CMakeFiles/pc1.dir/main.cpp.o
bin/pc1: src/pc1/CMakeFiles/pc1.dir/build.make
bin/pc1: src/pc1/CMakeFiles/pc1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/pc1"
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pc1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pc1/CMakeFiles/pc1.dir/build: bin/pc1

.PHONY : src/pc1/CMakeFiles/pc1.dir/build

src/pc1/CMakeFiles/pc1.dir/requires: src/pc1/CMakeFiles/pc1.dir/__/SafePthreadExtra/SafePthreadExtra.cpp.o.requires
src/pc1/CMakeFiles/pc1.dir/requires: src/pc1/CMakeFiles/pc1.dir/pc1.cpp.o.requires
src/pc1/CMakeFiles/pc1.dir/requires: src/pc1/CMakeFiles/pc1.dir/main.cpp.o.requires

.PHONY : src/pc1/CMakeFiles/pc1.dir/requires

src/pc1/CMakeFiles/pc1.dir/clean:
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 && $(CMAKE_COMMAND) -P CMakeFiles/pc1.dir/cmake_clean.cmake
.PHONY : src/pc1/CMakeFiles/pc1.dir/clean

src/pc1/CMakeFiles/pc1.dir/depend:
	cd /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/src/pc1 /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1 /home/fuookami/文档/Project/OperatingSystemSourceDesign/Test/cmake-build-debug/src/pc1/CMakeFiles/pc1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pc1/CMakeFiles/pc1.dir/depend

