/**
 *  * Project C++49期提高
 *   */

#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include "Socket.h"
#include "InetAddress.h"

using std::string;

#ifndef __ERROR_CHECK__
#define __ERROR_CHECK__

#include <stdio.h>
using std::string;

/**
 *  * 错误检查宏
 *   * @param ret 函数返回值
 *    * @param val 期望值
 *     * @param msg 错误消息
 *      */
inline void error_check(int ret, int val, const string& msg) {
    if (ret == val) {
        perror(msg.c_str());

    }

}

#endif

class Acceptor {
public:
    /**
     *      * 构造函数
     *           * @param ip IP 地址
     *                * @param port 端口号
     *                     */
    Acceptor(const string& ip, unsigned short port);

    /**
     *      * 析构函数
     *           */
    ~Acceptor();

    /**
     *      * 准备接受连接请求
     *           */
    void ready();

    /**
     *      * 接受连接请求
     *           * @return 新的套接字文件描述符
     *                */
    int accept();

    /**
     *      * 获取套接字文件描述符
     *           * @return 套接字文件描述符
     *                */
    int fd();

private:
    /**
     *      * 设置地址重用
     *           */
    void setReuseAddr();

    /**
     *      * 设置端口重用
     *           */
    void setReusePort();

    /**
     *      * 绑定套接字
     *           */
    void bind();

    /**
     *      * 监听连接请求
     *           */
    void listen();

    Socket _sock;  // Socket 对象
    InetAddress _addr;  // InetAddress 对象

};

#endif //_ACCEPTOR_H

