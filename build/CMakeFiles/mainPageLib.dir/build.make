# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qml/serch/search_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qml/serch/search_engine/build

# Include any dependencies generated for this target.
include CMakeFiles/mainPageLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mainPageLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mainPageLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainPageLib.dir/flags.make

CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o: ../src/pageLib/mainPageLib.cpp
CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o -MF CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o -c /home/qml/serch/search_engine/src/pageLib/mainPageLib.cpp

CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/pageLib/mainPageLib.cpp > CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.i

CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/pageLib/mainPageLib.cpp -o CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.s

CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o: ../src/Configuration.cpp
CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o -MF CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o -c /home/qml/serch/search_engine/src/Configuration.cpp

CMakeFiles/mainPageLib.dir/src/Configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/Configuration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/Configuration.cpp > CMakeFiles/mainPageLib.dir/src/Configuration.cpp.i

CMakeFiles/mainPageLib.dir/src/Configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/Configuration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/Configuration.cpp -o CMakeFiles/mainPageLib.dir/src/Configuration.cpp.s

CMakeFiles/mainPageLib.dir/src/mylog.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/mylog.cpp.o: ../src/mylog.cpp
CMakeFiles/mainPageLib.dir/src/mylog.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mainPageLib.dir/src/mylog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/mylog.cpp.o -MF CMakeFiles/mainPageLib.dir/src/mylog.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/mylog.cpp.o -c /home/qml/serch/search_engine/src/mylog.cpp

CMakeFiles/mainPageLib.dir/src/mylog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/mylog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/mylog.cpp > CMakeFiles/mainPageLib.dir/src/mylog.cpp.i

CMakeFiles/mainPageLib.dir/src/mylog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/mylog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/mylog.cpp -o CMakeFiles/mainPageLib.dir/src/mylog.cpp.s

CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o: ../src/pageLib/offsetPage.cpp
CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o -MF CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o -c /home/qml/serch/search_engine/src/pageLib/offsetPage.cpp

CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/pageLib/offsetPage.cpp > CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.i

CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/pageLib/offsetPage.cpp -o CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.s

CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o: ../src/pageLib/simHash.cpp
CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o -MF CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o -c /home/qml/serch/search_engine/src/pageLib/simHash.cpp

CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/pageLib/simHash.cpp > CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.i

CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/pageLib/simHash.cpp -o CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.s

CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o: ../src/pageLib/webPage.cpp
CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o -MF CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o -c /home/qml/serch/search_engine/src/pageLib/webPage.cpp

CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/pageLib/webPage.cpp > CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.i

CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/pageLib/webPage.cpp -o CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.s

CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o: CMakeFiles/mainPageLib.dir/flags.make
CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o: ../src/dict/split_tool.cpp
CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o: CMakeFiles/mainPageLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o -MF CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o.d -o CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o -c /home/qml/serch/search_engine/src/dict/split_tool.cpp

CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/dict/split_tool.cpp > CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.i

CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/dict/split_tool.cpp -o CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.s

# Object files for target mainPageLib
mainPageLib_OBJECTS = \
"CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/mylog.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o" \
"CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o"

# External object files for target mainPageLib
mainPageLib_EXTERNAL_OBJECTS =

mainPageLib: CMakeFiles/mainPageLib.dir/src/pageLib/mainPageLib.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/Configuration.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/mylog.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/pageLib/offsetPage.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/pageLib/simHash.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/pageLib/webPage.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/src/dict/split_tool.cpp.o
mainPageLib: CMakeFiles/mainPageLib.dir/build.make
mainPageLib: CMakeFiles/mainPageLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable mainPageLib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainPageLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainPageLib.dir/build: mainPageLib
.PHONY : CMakeFiles/mainPageLib.dir/build

CMakeFiles/mainPageLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainPageLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainPageLib.dir/clean

CMakeFiles/mainPageLib.dir/depend:
	cd /home/qml/serch/search_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qml/serch/search_engine /home/qml/serch/search_engine /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build/CMakeFiles/mainPageLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainPageLib.dir/depend

