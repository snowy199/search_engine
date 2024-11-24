/**
 *  * Project C++49期提高
 *   */

#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H

#include <string>
#include <sys/socket.h>
#include <sstream>
#include <memory>
#include <functional>
#include <sys/eventfd.h>
#include <unistd.h>
#include "SocketIO.h"
#include "InetAddress.h"

using std::string;

class EventLoop;

class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
public:
    using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
    using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;

    /**
     *      * 构造函数
     *           * @param fd 文件描述符
     *                * @param loop EventLoop对象
     *                     */
    explicit TcpConnection(int fd, EventLoop& loop);

    ~TcpConnection();

    /**
     *      * 发送消息
     *           * @param msg 要发送的消息
     *                */
    void send(const string& msg);

    /**
     *      * 接收消息
     *           * @return 接收到的消息
     *                */
    string receive();

    /**
     *      * 将TcpConnection转换为字符串表示
     *           * @return TcpConnection的字符串表示
     *                */
    string toString();

    /**
     *      * 判断TcpConnection是否已关闭
     *           * @return 如果TcpConnection已关闭返回true，否则返回false
     *                */
    bool isClosed();

    /**
     *      * 设置回调函数
     *           * @param connection 连接回调函数
     *                * @param message 消息回调函数
     *                     * @param closeCb 关闭回调函数
     *                          */
    void setCallback(TcpConnectionCallback& connection, TcpConnectionCallback& message, TcpConnectionCallback& closeCb);

    /**
     *      * 处理新连接的回调函数
     *           */
    void handleNewConnectionCallback();

    /**
     *      * 处理消息的回调函数
     *           */
    void handleMessageCallabck();

    /**
     *      * 处理关闭连接的回调函数
     *           */
    void hanleCloseCallback();

    /**
     *      * 添加发送消息到缓冲区
     *           * @param msg 要发送的消息
     *                */
    void addSendBc(const string& msg);

private:
    EventLoop& _loop;                   // EventLoop对象
    SocketIO _socketIO;                 // SocketIO对象，用于读写数据
    InetAddress _localAddr;             // 本地地址
    InetAddress _peerAddr;              // 远程地址
    TcpConnectionCallback _onConnectionCb;    // 连接回调函数
    TcpConnectionCallback _onMessageCb;       // 消息回调函数
    TcpConnectionCallback _onCloseCb;         // 关闭回调函数

    /**
     *      * 获取本地地址
     *           * @return 本地地址
     *                */
    InetAddress getLocalAddr();

    /**
     *      * 获取远程地址
     *           * @return 远程地址
     *                */
    InetAddress getPeerAddr();

};

#endif //_TCPCONNECTION_H

