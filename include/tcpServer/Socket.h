/**
 *  * Project C++49期提高
 *   */

#ifndef _SOCKET_H
#define _SOCKET_H

#include <sys/socket.h>
#include <string>
#include <unistd.h>

#ifndef __ERROR_CHECK__
#define __ERROR_CHECK__

#include <stdio.h>
using std::string;

/**
 *  * 错误检查宏
 *   * @param ret 函数返回值
 *    * @param val 预期的值
 *     * @param msg 错误信息
 *      */
inline void error_check(int ret, int val, const string& msg) {
    if (ret == val) {
        perror(msg.c_str());

    }

}
#endif

class Socket {
public:
    /**
     *      * 构造函数
     *           */
    Socket();

    /**
     *      * 构造函数
     *           * @param fd 文件描述符
     *                */
    explicit Socket(int fd);

    /**
     *      * 析构函数
     *           */
    ~Socket();

    /**
     *      * 获取文件描述符
     *           * @return 文件描述符
     *                */
    int fd();

private:
    int _fd;  // 文件描述符

};

#endif //_SOCKET_H

