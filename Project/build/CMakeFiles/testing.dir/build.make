# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testing.dir/flags.make

CMakeFiles/testing.dir/src/addToLibrary.c.o: CMakeFiles/testing.dir/flags.make
CMakeFiles/testing.dir/src/addToLibrary.c.o: ../src/addToLibrary.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/testing.dir/src/addToLibrary.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/testing.dir/src/addToLibrary.c.o   -c /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/src/addToLibrary.c

CMakeFiles/testing.dir/src/addToLibrary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testing.dir/src/addToLibrary.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/src/addToLibrary.c > CMakeFiles/testing.dir/src/addToLibrary.c.i

CMakeFiles/testing.dir/src/addToLibrary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testing.dir/src/addToLibrary.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/src/addToLibrary.c -o CMakeFiles/testing.dir/src/addToLibrary.c.s

CMakeFiles/testing.dir/src/addToLibrary.c.o.requires:
.PHONY : CMakeFiles/testing.dir/src/addToLibrary.c.o.requires

CMakeFiles/testing.dir/src/addToLibrary.c.o.provides: CMakeFiles/testing.dir/src/addToLibrary.c.o.requires
	$(MAKE) -f CMakeFiles/testing.dir/build.make CMakeFiles/testing.dir/src/addToLibrary.c.o.provides.build
.PHONY : CMakeFiles/testing.dir/src/addToLibrary.c.o.provides

CMakeFiles/testing.dir/src/addToLibrary.c.o.provides.build: CMakeFiles/testing.dir/src/addToLibrary.c.o

CMakeFiles/testing.dir/test/test_addToLibrary.c.o: CMakeFiles/testing.dir/flags.make
CMakeFiles/testing.dir/test/test_addToLibrary.c.o: ../test/test_addToLibrary.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/testing.dir/test/test_addToLibrary.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/testing.dir/test/test_addToLibrary.c.o   -c /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/test/test_addToLibrary.c

CMakeFiles/testing.dir/test/test_addToLibrary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testing.dir/test/test_addToLibrary.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/test/test_addToLibrary.c > CMakeFiles/testing.dir/test/test_addToLibrary.c.i

CMakeFiles/testing.dir/test/test_addToLibrary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testing.dir/test/test_addToLibrary.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/test/test_addToLibrary.c -o CMakeFiles/testing.dir/test/test_addToLibrary.c.s

CMakeFiles/testing.dir/test/test_addToLibrary.c.o.requires:
.PHONY : CMakeFiles/testing.dir/test/test_addToLibrary.c.o.requires

CMakeFiles/testing.dir/test/test_addToLibrary.c.o.provides: CMakeFiles/testing.dir/test/test_addToLibrary.c.o.requires
	$(MAKE) -f CMakeFiles/testing.dir/build.make CMakeFiles/testing.dir/test/test_addToLibrary.c.o.provides.build
.PHONY : CMakeFiles/testing.dir/test/test_addToLibrary.c.o.provides

CMakeFiles/testing.dir/test/test_addToLibrary.c.o.provides.build: CMakeFiles/testing.dir/test/test_addToLibrary.c.o

CMakeFiles/testing.dir/unity/unity.c.o: CMakeFiles/testing.dir/flags.make
CMakeFiles/testing.dir/unity/unity.c.o: ../unity/unity.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/testing.dir/unity/unity.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/testing.dir/unity/unity.c.o   -c /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/unity/unity.c

CMakeFiles/testing.dir/unity/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testing.dir/unity/unity.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/unity/unity.c > CMakeFiles/testing.dir/unity/unity.c.i

CMakeFiles/testing.dir/unity/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testing.dir/unity/unity.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/unity/unity.c -o CMakeFiles/testing.dir/unity/unity.c.s

CMakeFiles/testing.dir/unity/unity.c.o.requires:
.PHONY : CMakeFiles/testing.dir/unity/unity.c.o.requires

CMakeFiles/testing.dir/unity/unity.c.o.provides: CMakeFiles/testing.dir/unity/unity.c.o.requires
	$(MAKE) -f CMakeFiles/testing.dir/build.make CMakeFiles/testing.dir/unity/unity.c.o.provides.build
.PHONY : CMakeFiles/testing.dir/unity/unity.c.o.provides

CMakeFiles/testing.dir/unity/unity.c.o.provides.build: CMakeFiles/testing.dir/unity/unity.c.o

# Object files for target testing
testing_OBJECTS = \
"CMakeFiles/testing.dir/src/addToLibrary.c.o" \
"CMakeFiles/testing.dir/test/test_addToLibrary.c.o" \
"CMakeFiles/testing.dir/unity/unity.c.o"

# External object files for target testing
testing_EXTERNAL_OBJECTS =

testing: CMakeFiles/testing.dir/src/addToLibrary.c.o
testing: CMakeFiles/testing.dir/test/test_addToLibrary.c.o
testing: CMakeFiles/testing.dir/unity/unity.c.o
testing: CMakeFiles/testing.dir/build.make
testing: CMakeFiles/testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable testing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testing.dir/build: testing
.PHONY : CMakeFiles/testing.dir/build

CMakeFiles/testing.dir/requires: CMakeFiles/testing.dir/src/addToLibrary.c.o.requires
CMakeFiles/testing.dir/requires: CMakeFiles/testing.dir/test/test_addToLibrary.c.o.requires
CMakeFiles/testing.dir/requires: CMakeFiles/testing.dir/unity/unity.c.o.requires
.PHONY : CMakeFiles/testing.dir/requires

CMakeFiles/testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testing.dir/clean

CMakeFiles/testing.dir/depend:
	cd /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build /home/cserv1_a/elec_ug/el18mhi/c_project_2/Project/build/CMakeFiles/testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testing.dir/depend

