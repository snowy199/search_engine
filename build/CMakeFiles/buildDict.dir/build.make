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
include CMakeFiles/buildDict.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/buildDict.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/buildDict.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/buildDict.dir/flags.make

CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o: CMakeFiles/buildDict.dir/flags.make
CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o: ../src/dict/mainDictCreate.cpp
CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o: CMakeFiles/buildDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o -MF CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o.d -o CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o -c /home/qml/serch/search_engine/src/dict/mainDictCreate.cpp

CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/dict/mainDictCreate.cpp > CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.i

CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/dict/mainDictCreate.cpp -o CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.s

CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o: CMakeFiles/buildDict.dir/flags.make
CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o: ../src/dict/dict_producer.cpp
CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o: CMakeFiles/buildDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o -MF CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o.d -o CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o -c /home/qml/serch/search_engine/src/dict/dict_producer.cpp

CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/dict/dict_producer.cpp > CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.i

CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/dict/dict_producer.cpp -o CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.s

CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o: CMakeFiles/buildDict.dir/flags.make
CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o: ../src/dict/split_tool.cpp
CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o: CMakeFiles/buildDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o -MF CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o.d -o CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o -c /home/qml/serch/search_engine/src/dict/split_tool.cpp

CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/dict/split_tool.cpp > CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.i

CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/dict/split_tool.cpp -o CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.s

CMakeFiles/buildDict.dir/src/Configuration.cpp.o: CMakeFiles/buildDict.dir/flags.make
CMakeFiles/buildDict.dir/src/Configuration.cpp.o: ../src/Configuration.cpp
CMakeFiles/buildDict.dir/src/Configuration.cpp.o: CMakeFiles/buildDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/buildDict.dir/src/Configuration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buildDict.dir/src/Configuration.cpp.o -MF CMakeFiles/buildDict.dir/src/Configuration.cpp.o.d -o CMakeFiles/buildDict.dir/src/Configuration.cpp.o -c /home/qml/serch/search_engine/src/Configuration.cpp

CMakeFiles/buildDict.dir/src/Configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildDict.dir/src/Configuration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/Configuration.cpp > CMakeFiles/buildDict.dir/src/Configuration.cpp.i

CMakeFiles/buildDict.dir/src/Configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildDict.dir/src/Configuration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/Configuration.cpp -o CMakeFiles/buildDict.dir/src/Configuration.cpp.s

CMakeFiles/buildDict.dir/src/mylog.cpp.o: CMakeFiles/buildDict.dir/flags.make
CMakeFiles/buildDict.dir/src/mylog.cpp.o: ../src/mylog.cpp
CMakeFiles/buildDict.dir/src/mylog.cpp.o: CMakeFiles/buildDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/buildDict.dir/src/mylog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/buildDict.dir/src/mylog.cpp.o -MF CMakeFiles/buildDict.dir/src/mylog.cpp.o.d -o CMakeFiles/buildDict.dir/src/mylog.cpp.o -c /home/qml/serch/search_engine/src/mylog.cpp

CMakeFiles/buildDict.dir/src/mylog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buildDict.dir/src/mylog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qml/serch/search_engine/src/mylog.cpp > CMakeFiles/buildDict.dir/src/mylog.cpp.i

CMakeFiles/buildDict.dir/src/mylog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buildDict.dir/src/mylog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qml/serch/search_engine/src/mylog.cpp -o CMakeFiles/buildDict.dir/src/mylog.cpp.s

# Object files for target buildDict
buildDict_OBJECTS = \
"CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o" \
"CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o" \
"CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o" \
"CMakeFiles/buildDict.dir/src/Configuration.cpp.o" \
"CMakeFiles/buildDict.dir/src/mylog.cpp.o"

# External object files for target buildDict
buildDict_EXTERNAL_OBJECTS =

buildDict: CMakeFiles/buildDict.dir/src/dict/mainDictCreate.cpp.o
buildDict: CMakeFiles/buildDict.dir/src/dict/dict_producer.cpp.o
buildDict: CMakeFiles/buildDict.dir/src/dict/split_tool.cpp.o
buildDict: CMakeFiles/buildDict.dir/src/Configuration.cpp.o
buildDict: CMakeFiles/buildDict.dir/src/mylog.cpp.o
buildDict: CMakeFiles/buildDict.dir/build.make
buildDict: CMakeFiles/buildDict.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qml/serch/search_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable buildDict"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buildDict.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/buildDict.dir/build: buildDict
.PHONY : CMakeFiles/buildDict.dir/build

CMakeFiles/buildDict.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/buildDict.dir/cmake_clean.cmake
.PHONY : CMakeFiles/buildDict.dir/clean

CMakeFiles/buildDict.dir/depend:
	cd /home/qml/serch/search_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qml/serch/search_engine /home/qml/serch/search_engine /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build /home/qml/serch/search_engine/build/CMakeFiles/buildDict.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/buildDict.dir/depend
