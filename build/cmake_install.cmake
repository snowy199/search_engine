# Install script for directory: /home/qml/serch/search_engine

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/buildDict")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/buildDict")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/buildDict")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/queryCn")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/queryCn")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryCn")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/testCache")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/testCache")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/testCache")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/mainPageLib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/mainPageLib")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/mainPageLib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/queryTest")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/queryTest")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/queryTest")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/client/bin/client")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/client/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/client")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/client/bin/client")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/qml/serch/search_engine/bin/searchSever")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/qml/serch/search_engine/bin" TYPE EXECUTABLE FILES "/home/qml/serch/search_engine/build/searchSever")
  if(EXISTS "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/qml/serch/search_engine/bin/searchSever")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/qml/serch/search_engine/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
