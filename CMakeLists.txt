cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置编译选项
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件 buildDict
add_executable(buildDict
    src/dict/mainDictCreate.cpp
    src/dict/dict_producer.cpp
    src/dict/split_tool.cpp
    src/Configuration.cpp
    src/mylog.cpp
)
# 添加头文件搜索路径
target_include_directories(buildDict PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(buildDict PRIVATE Threads::Threads)
# 链接log4cpp库
target_link_libraries(buildDict PRIVATE log4cpp)


# 添加可执行文件 keyRecommander
add_executable(queryCn
    src/dict/key_recommander.cpp
    src/dict/dict_producer.cpp
    src/dict/dictionary.cpp
    src/dict/split_tool.cpp
    src/Configuration.cpp
    src/mylog.cpp
    src/LRUCache/CacheManager.cpp
    src/LRUCache/LRUCache.cpp
    src/dict/mainqueryCn.cpp
)
# 添加头文件搜索路径
target_include_directories(queryCn PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(queryCn PRIVATE Threads::Threads)
# 链接log4cpp库
target_link_libraries(queryCn PRIVATE log4cpp)

# 添加可执行文件 keyRecommander
add_executable(testCache
    src/LRUCache/testLRUCache.cpp
    src/Configuration.cpp
    src/mylog.cpp
    src/LRUCache/CacheManager.cpp
    src/LRUCache/LRUCache.cpp
)
# 添加头文件搜索路径
target_include_directories(testCache PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(testCache PRIVATE Threads::Threads)
# 链接log4cpp库
target_link_libraries(testCache PRIVATE log4cpp)


# 添加可执行文件 keyRecommander
add_executable(mainPageLib
    src/pageLib/mainPageLib.cpp
    src/Configuration.cpp
    src/mylog.cpp
    src/pageLib/offsetPage.cpp
    src/pageLib/simHash.cpp
    src/pageLib/webPage.cpp
    src/dict/split_tool.cpp
)
# 添加头文件搜索路径
target_include_directories(mainPageLib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(mainPageLib PRIVATE Threads::Threads)
# 链接log4cpp库
target_link_libraries(mainPageLib PRIVATE log4cpp)
# 链接 tinyxml2 库
target_link_libraries(mainPageLib PRIVATE tinyxml2)


# 添加可执行文件 keyRecommander
add_executable(queryTest
    src/webPage/test.cpp
    src/Configuration.cpp
    src/mylog.cpp
    src/webPage/WebPageQuery.cpp
    src/webPage/WebPageReader.cpp
    src/dict/split_tool.cpp
    src/redis.cpp
)
# 添加头文件搜索路径
target_include_directories(queryTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(queryTest PRIVATE Threads::Threads)
# 链接log4cpp库
target_link_libraries(queryTest PRIVATE log4cpp)
# 链接 tinyxml2 库
target_link_libraries(queryTest PRIVATE tinyxml2)
target_link_libraries(queryTest PRIVATE redis++)

# add_subdirectory(src/LRUCache testCache)
# 指定安装规则
install(TARGETS buildDict DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS queryCn DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS testCache DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS mainPageLib DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS queryTest DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
