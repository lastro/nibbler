# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_COMMAND = /nfs/zfs-student-5/users/2013/amusic/.brew/Cellar/cmake/3.1.3/bin/cmake

# The command to remove a file.
RM = /nfs/zfs-student-5/users/2013/amusic/.brew/Cellar/cmake/3.1.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-5/users/2013/amusic/work/projets/v2/nibbler/repo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-5/users/2013/amusic/work/projets/v2/nibbler/repo

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Volumes/Data/nfs/zfs-student-5/users/2013/amusic/.brew/Cellar/cmake/3.1.3/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Volumes/Data/nfs/zfs-student-5/users/2013/amusic/.brew/Cellar/cmake/3.1.3/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /nfs/zfs-student-5/users/2013/amusic/work/projets/v2/nibbler/repo/CMakeFiles /nfs/zfs-student-5/users/2013/amusic/work/projets/v2/nibbler/repo/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /nfs/zfs-student-5/users/2013/amusic/work/projets/v2/nibbler/repo/CMakeFiles 0
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
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named nibbler

# Build rule for target.
nibbler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 nibbler
.PHONY : nibbler

# fast build rule for target.
nibbler/fast:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/build
.PHONY : nibbler/fast

Qt/src/lib.o: Qt/src/lib.cpp.o
.PHONY : Qt/src/lib.o

# target to build an object file
Qt/src/lib.cpp.o:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/lib.cpp.o
.PHONY : Qt/src/lib.cpp.o

Qt/src/lib.i: Qt/src/lib.cpp.i
.PHONY : Qt/src/lib.i

# target to preprocess a source file
Qt/src/lib.cpp.i:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/lib.cpp.i
.PHONY : Qt/src/lib.cpp.i

Qt/src/lib.s: Qt/src/lib.cpp.s
.PHONY : Qt/src/lib.s

# target to generate assembly for a file
Qt/src/lib.cpp.s:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/lib.cpp.s
.PHONY : Qt/src/lib.cpp.s

Qt/src/window.o: Qt/src/window.cpp.o
.PHONY : Qt/src/window.o

# target to build an object file
Qt/src/window.cpp.o:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/window.cpp.o
.PHONY : Qt/src/window.cpp.o

Qt/src/window.i: Qt/src/window.cpp.i
.PHONY : Qt/src/window.i

# target to preprocess a source file
Qt/src/window.cpp.i:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/window.cpp.i
.PHONY : Qt/src/window.cpp.i

Qt/src/window.s: Qt/src/window.cpp.s
.PHONY : Qt/src/window.s

# target to generate assembly for a file
Qt/src/window.cpp.s:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/Qt/src/window.cpp.s
.PHONY : Qt/src/window.cpp.s

main/src/Element.o: main/src/Element.cpp.o
.PHONY : main/src/Element.o

# target to build an object file
main/src/Element.cpp.o:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Element.cpp.o
.PHONY : main/src/Element.cpp.o

main/src/Element.i: main/src/Element.cpp.i
.PHONY : main/src/Element.i

# target to preprocess a source file
main/src/Element.cpp.i:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Element.cpp.i
.PHONY : main/src/Element.cpp.i

main/src/Element.s: main/src/Element.cpp.s
.PHONY : main/src/Element.s

# target to generate assembly for a file
main/src/Element.cpp.s:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Element.cpp.s
.PHONY : main/src/Element.cpp.s

main/src/Lib.o: main/src/Lib.cpp.o
.PHONY : main/src/Lib.o

# target to build an object file
main/src/Lib.cpp.o:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Lib.cpp.o
.PHONY : main/src/Lib.cpp.o

main/src/Lib.i: main/src/Lib.cpp.i
.PHONY : main/src/Lib.i

# target to preprocess a source file
main/src/Lib.cpp.i:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Lib.cpp.i
.PHONY : main/src/Lib.cpp.i

main/src/Lib.s: main/src/Lib.cpp.s
.PHONY : main/src/Lib.s

# target to generate assembly for a file
main/src/Lib.cpp.s:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/Lib.cpp.s
.PHONY : main/src/Lib.cpp.s

main/src/main.o: main/src/main.cpp.o
.PHONY : main/src/main.o

# target to build an object file
main/src/main.cpp.o:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/main.cpp.o
.PHONY : main/src/main.cpp.o

main/src/main.i: main/src/main.cpp.i
.PHONY : main/src/main.i

# target to preprocess a source file
main/src/main.cpp.i:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/main.cpp.i
.PHONY : main/src/main.cpp.i

main/src/main.s: main/src/main.cpp.s
.PHONY : main/src/main.s

# target to generate assembly for a file
main/src/main.cpp.s:
	$(MAKE) -f CMakeFiles/nibbler.dir/build.make CMakeFiles/nibbler.dir/main/src/main.cpp.s
.PHONY : main/src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... nibbler"
	@echo "... Qt/src/lib.o"
	@echo "... Qt/src/lib.i"
	@echo "... Qt/src/lib.s"
	@echo "... Qt/src/window.o"
	@echo "... Qt/src/window.i"
	@echo "... Qt/src/window.s"
	@echo "... main/src/Element.o"
	@echo "... main/src/Element.i"
	@echo "... main/src/Element.s"
	@echo "... main/src/Lib.o"
	@echo "... main/src/Lib.i"
	@echo "... main/src/Lib.s"
	@echo "... main/src/main.o"
	@echo "... main/src/main.i"
	@echo "... main/src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

