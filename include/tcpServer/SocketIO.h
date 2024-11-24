/**
 *  * Project SearchEngine
 *   */

#ifndef _SOCKETIO_H
#define _SOCKETIO_H

#include <string>

using std::string;

class SocketIO {
public:
    /**
     *      * 构造函数
     *           * @param fd 文件描述符
     *                */
    SocketIO(int fd);

    /**
     *      * 析构函数
     *           */
    ~SocketIO();

    /**
     *      * 接收数据
     *           * @return 接收到的数据字符串
     *                */
    string receive();

    /**
     *      * 发送数据
     *           * @param str 待发送的数据字符串
     *                * @return 成功发送的字节数
     *                     */
    int write(const string& str);

    /**
     *      * 获取文件描述符
     *           * @return 文件描述符
     *                */
    int fd();

    /**
     *      * 读取固定长度的数据
     *           * @param buf 缓冲区指针
     *                * @param len 待读取的长度
     *                     * @return 实际读取的字节数
     *                          */
    int readn(char* buf, int len);

    /**
     *      * 写入固定长度的数据
     *           * @param buf 缓冲区指针
     *                * @param len 待写入的长度
     *                     * @return 实际写入的字节数
     *                          */
    int writen(const char* buf, int len);

private:
    int _fd;  // 文件描述符

};

#endif //_SOCKETIO_H

