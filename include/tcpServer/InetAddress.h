/**
 *  * Project C++49期提高
 *   */

#ifndef _INETADDRESS_H
#define _INETADDRESS_H

#include <string>
#include <arpa/inet.h>

using std::string;

class InetAddress {
public:
    /**
     *      * 构造函数
     *           * @param ip IP 地址
     *                * @param port 端口号
     *                     */
    InetAddress(const string& ip, unsigned short port);

    /**
     *      * 构造函数
     *           * @param addr sockaddr_in 结构体
     *                */
    InetAddress(const struct sockaddr_in& addr);

    /**
     *      * 析构函数
     *           */
    ~InetAddress();

    /**
     *      * 获取 IP 地址
     *           * @return IP 地址
     *                */
    string ip();

    /**
     *      * 获取端口号
     *           * @return 端口号
     *                */
    unsigned short port();

    /**
     *      * 获取 sockaddr_in 结构体指针
     *           * @return sockaddr_in 结构体指针
     *                */
    struct sockaddr_in* getSockaddrPtr();

private:
    struct sockaddr_in _addr;  // sockaddr_in 结构体

};

#endif //_INETADDRESS_H

