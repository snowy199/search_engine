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
include CMakeFiles/queryTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/queryTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/queryTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queryTest.dir/flags.make

CMakeFiles/queryTest.dir/src/webPage/test.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/webPage/test.cpp.o: ../src/webPage/test.cpp
CMakeFiles/queryTest.dir/src/webPage/test.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queryTest.dir/src/webPage/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/webPage/test.cpp.o -MF CMakeFiles/queryTest.dir/src/webPage/test.cpp.o.d -o CMakeFiles/queryTest.dir/src/webPage/test.cpp.o -c /home/qml/serch/search_engine/src/webPage/test.cpp

CMakeFiles/queryTest.dir/src/webPage/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/webPage/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/webPage/test.cpp > CMakeFiles/queryTest.dir/src/webPage/test.cpp.i

CMakeFiles/queryTest.dir/src/webPage/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/webPage/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/webPage/test.cpp -o CMakeFiles/queryTest.dir/src/webPage/test.cpp.s

CMakeFiles/queryTest.dir/src/Configuration.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/Configuration.cpp.o: ../src/Configuration.cpp
CMakeFiles/queryTest.dir/src/Configuration.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/queryTest.dir/src/Configuration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/Configuration.cpp.o -MF CMakeFiles/queryTest.dir/src/Configuration.cpp.o.d -o CMakeFiles/queryTest.dir/src/Configuration.cpp.o -c /home/qml/serch/search_engine/src/Configuration.cpp

CMakeFiles/queryTest.dir/src/Configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/Configuration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/Configuration.cpp > CMakeFiles/queryTest.dir/src/Configuration.cpp.i

CMakeFiles/queryTest.dir/src/Configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/Configuration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/Configuration.cpp -o CMakeFiles/queryTest.dir/src/Configuration.cpp.s

CMakeFiles/queryTest.dir/src/mylog.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/mylog.cpp.o: ../src/mylog.cpp
CMakeFiles/queryTest.dir/src/mylog.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/queryTest.dir/src/mylog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/mylog.cpp.o -MF CMakeFiles/queryTest.dir/src/mylog.cpp.o.d -o CMakeFiles/queryTest.dir/src/mylog.cpp.o -c /home/qml/serch/search_engine/src/mylog.cpp

CMakeFiles/queryTest.dir/src/mylog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/mylog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/mylog.cpp > CMakeFiles/queryTest.dir/src/mylog.cpp.i

CMakeFiles/queryTest.dir/src/mylog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/mylog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/mylog.cpp -o CMakeFiles/queryTest.dir/src/mylog.cpp.s

CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o: ../src/webPage/WebPageQuery.cpp
CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o -MF CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o.d -o CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o -c /home/qml/serch/search_engine/src/webPage/WebPageQuery.cpp

CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/webPage/WebPageQuery.cpp > CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.i

CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/webPage/WebPageQuery.cpp -o CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.s

CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o: ../src/webPage/WebPageReader.cpp
CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o -MF CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o.d -o CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o -c /home/qml/serch/search_engine/src/webPage/WebPageReader.cpp

CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/webPage/WebPageReader.cpp > CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.i

CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/webPage/WebPageReader.cpp -o CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.s

CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o: ../src/dict/split_tool.cpp
CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o -MF CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o.d -o CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o -c /home/qml/serch/search_engine/src/dict/split_tool.cpp

CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/dict/split_tool.cpp > CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.i

CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/dict/split_tool.cpp -o CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.s

CMakeFiles/queryTest.dir/src/redis.cpp.o: CMakeFiles/queryTest.dir/flags.make
CMakeFiles/queryTest.dir/src/redis.cpp.o: ../src/redis.cpp
CMakeFiles/queryTest.dir/src/redis.cpp.o: CMakeFiles/queryTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/queryTest.dir/src/redis.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queryTest.dir/src/redis.cpp.o -MF CMakeFiles/queryTest.dir/src/redis.cpp.o.d -o CMakeFiles/queryTest.dir/src/redis.cpp.o -c /home/qml/serch/search_engine/src/redis.cpp

CMakeFiles/queryTest.dir/src/redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryTest.dir/src/redis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/redis.cpp > CMakeFiles/queryTest.dir/src/redis.cpp.i

CMakeFiles/queryTest.dir/src/redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryTest.dir/src/redis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/redis.cpp -o CMakeFiles/queryTest.dir/src/redis.cpp.s

# Object files for target queryTest
queryTest_OBJECTS = \
"CMakeFiles/queryTest.dir/src/webPage/test.cpp.o" \
"CMakeFiles/queryTest.dir/src/Configuration.cpp.o" \
"CMakeFiles/queryTest.dir/src/mylog.cpp.o" \
"CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o" \
"CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o" \
"CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o" \
"CMakeFiles/queryTest.dir/src/redis.cpp.o"

# External object files for target queryTest
queryTest_EXTERNAL_OBJECTS =

queryTest: CMakeFiles/queryTest.dir/src/webPage/test.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/Configuration.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/mylog.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/webPage/WebPageQuery.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/webPage/WebPageReader.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/dict/split_tool.cpp.o
queryTest: CMakeFiles/queryTest.dir/src/redis.cpp.o
queryTest: CMakeFiles/queryTest.dir/build.make
queryTest: CMakeFiles/queryTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable queryTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queryTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queryTest.dir/build: queryTest
.PHONY : CMakeFiles/queryTest.dir/build

CMakeFiles/queryTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queryTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queryTest.dir/clean

CMakeFiles/queryTest.dir/depend:
	cd /home/qml/serch/search_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qml/serch/search_engine /home/qml/serch/search_engine /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build/CMakeFiles/queryTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queryTest.dir/depend
