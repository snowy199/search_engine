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


# 添加可执行文件 queryCn
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

# 添加可执行文件 testCache
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


# 添加可执行文件 mainPageLib
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


# 添加可执行文件 queryTest
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



# 添加可执行文件 searchSever
add_executable(searchSever
    src/tcpServer/Acceptor.cpp
    src/tcpServer/Condition.cpp
    src/tcpServer/EventLoop.cpp
    src/tcpServer/InetAddress.cpp
    src/tcpServer/mainSearchSever.cpp
    src/tcpServer/Mutex.cpp
    src/tcpServer/SearchServer.cpp
    src/tcpServer/Socket.cpp
    src/tcpServer/SocketIO.cpp
    src/tcpServer/Task.cpp
    src/tcpServer/TaskQueue.cpp
    src/tcpServer/TcpConnection.cpp
    src/tcpServer/TcpServer.cpp
    src/tcpServer/Thread.cpp  # 添加 Thread.cpp
    src/tcpServer/ThreadPool.cpp  # 添加 ThreadPool.cpp
    src/dict/dictionary.cpp
    src/dict/key_recommander.cpp
    src/dict/split_tool.cpp
    src/webPage/WebPageQuery.cpp
    src/webPage/WebPageReader.cpp
    src/Configuration.cpp
    src/mylog.cpp
    src/redis.cpp
    src/LRUCache/CacheManager.cpp
    src/LRUCache/CacheUpdateTask.cpp
    src/LRUCache/LRUCache.cpp
    src/LRUCache/TimerManager.cpp
)
# 添加头文件搜索路径# 添加头文件搜索路径
target_include_directories(searchSever PRIVATE
    include
)
# 链接 pthread 库
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(searchSever PRIVATE Threads::Threads)

target_link_libraries(searchSever PRIVATE redis++)

# 链接log4cpp库
target_link_libraries(searchSever PRIVATE log4cpp)
# add_subdirectory(src/LRUCache testCache)


# 添加可执行文件 client
add_executable(client
    client/src/Configuration.cpp
    client/src/Connection.cpp
    client/src/InetAddress.cpp
    client/src/mainClient.cpp
    client/src/Socket.cpp
    client/src/SocketIO.cpp
    client/src/TcpClient.cpp
    client/src/TcpConnection.cpp
)

# 添加头文件搜索路径
target_include_directories(client PRIVATE
    client
    # include
)
# 指定安装规则
install(TARGETS buildDict DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS queryCn DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS testCache DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS mainPageLib DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS queryTest DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS client DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/client/bin)
install(TARGETS searchSever DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)