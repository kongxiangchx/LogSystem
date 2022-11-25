# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/chx/workspace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chx/workspace

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chx/workspace/CMakeFiles /home/chx/workspace/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chx/workspace/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_config

# Build rule for target.
test_config: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_config
.PHONY : test_config

# fast build rule for target.
test_config/fast:
	$(MAKE) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/build
.PHONY : test_config/fast

#=============================================================================
# Target rules for targets named chx

# Build rule for target.
chx: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 chx
.PHONY : chx

# fast build rule for target.
chx/fast:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/build
.PHONY : chx/fast

chx/config.o: chx/config.cc.o

.PHONY : chx/config.o

# target to build an object file
chx/config.cc.o:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/config.cc.o
.PHONY : chx/config.cc.o

chx/config.i: chx/config.cc.i

.PHONY : chx/config.i

# target to preprocess a source file
chx/config.cc.i:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/config.cc.i
.PHONY : chx/config.cc.i

chx/config.s: chx/config.cc.s

.PHONY : chx/config.s

# target to generate assembly for a file
chx/config.cc.s:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/config.cc.s
.PHONY : chx/config.cc.s

chx/log.o: chx/log.cc.o

.PHONY : chx/log.o

# target to build an object file
chx/log.cc.o:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/log.cc.o
.PHONY : chx/log.cc.o

chx/log.i: chx/log.cc.i

.PHONY : chx/log.i

# target to preprocess a source file
chx/log.cc.i:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/log.cc.i
.PHONY : chx/log.cc.i

chx/log.s: chx/log.cc.s

.PHONY : chx/log.s

# target to generate assembly for a file
chx/log.cc.s:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/log.cc.s
.PHONY : chx/log.cc.s

chx/util.o: chx/util.cc.o

.PHONY : chx/util.o

# target to build an object file
chx/util.cc.o:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/util.cc.o
.PHONY : chx/util.cc.o

chx/util.i: chx/util.cc.i

.PHONY : chx/util.i

# target to preprocess a source file
chx/util.cc.i:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/util.cc.i
.PHONY : chx/util.cc.i

chx/util.s: chx/util.cc.s

.PHONY : chx/util.s

# target to generate assembly for a file
chx/util.cc.s:
	$(MAKE) -f CMakeFiles/chx.dir/build.make CMakeFiles/chx.dir/chx/util.cc.s
.PHONY : chx/util.cc.s

tests/test_config.o: tests/test_config.cc.o

.PHONY : tests/test_config.o

# target to build an object file
tests/test_config.cc.o:
	$(MAKE) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.o
.PHONY : tests/test_config.cc.o

tests/test_config.i: tests/test_config.cc.i

.PHONY : tests/test_config.i

# target to preprocess a source file
tests/test_config.cc.i:
	$(MAKE) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.i
.PHONY : tests/test_config.cc.i

tests/test_config.s: tests/test_config.cc.s

.PHONY : tests/test_config.s

# target to generate assembly for a file
tests/test_config.cc.s:
	$(MAKE) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.s
.PHONY : tests/test_config.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... test_config"
	@echo "... chx"
	@echo "... chx/config.o"
	@echo "... chx/config.i"
	@echo "... chx/config.s"
	@echo "... chx/log.o"
	@echo "... chx/log.i"
	@echo "... chx/log.s"
	@echo "... chx/util.o"
	@echo "... chx/util.i"
	@echo "... chx/util.s"
	@echo "... tests/test_config.o"
	@echo "... tests/test_config.i"
	@echo "... tests/test_config.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

