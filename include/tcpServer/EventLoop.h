/**
 *  * Project C++49期提高
 *   */

#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H

#include <vector>
#include <functional>
#include <sys/epoll.h>
#include <memory>
#include <unordered_map>
#include <string.h>
#include <iostream>
#include "Mutex.h"

using std::function;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class TcpConnection;
class Acceptor;

class EventLoop {
public:
    using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
    using TcpConnectionCallback = function<void(const TcpConnectionPtr&)>;
    using SendCb = function<void()>;

    /**
     *      * 构造函数
     *           * @param acceptor 接收器对象的引用
     *                */
    EventLoop(Acceptor& acceptor);

    /**
     *      * 析构函数
     *           */
    ~EventLoop();

    /**
     *      * 事件循环
     *           */
    void loop();

    /**
     *      * 停止事件循环
     *           */
    void unloop();

    /**
     *      * 设置回调函数
     *           * @param connection 连接回调函数
     *                * @param message 消息回调函数
     *                     * @param close 关闭回调函数
     *                          */
    void setCallback(TcpConnectionCallback&& connection, TcpConnectionCallback&& message, TcpConnectionCallback&& close);

    /**
     *      * 添加发送回调函数
     *           * @param cb 发送回调函数
     *                */
    void addSendBc(SendCb&& cb);

private:
    int _epfd;  // epoll 文件描述符
    int _evfd;  // event 文件描述符
    bool _isLooping;  // 事件循环标志
    Acceptor& _acceptor;  // 接收器对象的引用
    vector<struct epoll_event> _evtList;  // epoll 事件列表
    unordered_map<int, TcpConnectionPtr> _conns;  // 连接对象的哈希映射
    TcpConnectionCallback _onConnectionCb;  // 连接回调函数
    TcpConnectionCallback _onMessageCb;  // 消息回调函数
    TcpConnectionCallback _onCloseCb;  // 关闭回调函数
    Mutex _mutex;  // 互斥锁
    vector<SendCb> _sendTasks;  // 发送任务列表

    /**
     *      * 等待 epoll 文件描述符上的事件
     *           */
    void waitEpollFd();

    /**
     *      * 处理新的连接请求
     *           */
    void handleNewConnection();

    /**
     *      * 处理消息
     *           * @param fd 文件描述符
     *                */
    void handleMessage(int fd);

    /**
     *      * 创建 epoll 文件描述符
     *           * @return epoll 文件描述符
     *                */
    int createEpollFd();

    /**
     *      * 创建 event 文件描述符
     *           * @return event 文件描述符
     *                */
    int createEventFd();

    /**
     *      * 添加 epoll 可读文件描述符
     *           * @param fd 文件描述符
     *                */
    void addEpollReadFd(int fd);

    /**
     *      * 删除 epoll 可读文件描述符
     *           * @param fd 文件描述符
     *                */
    void delEpollReadFd(int fd);

    /**
     *      * 发送消息
     *           */
    void sendMsg();

    /**
     *      * 处理读事件
     *           */
    void handleRead();

    /**
     *      * 唤醒发送消息
     *           */
    void wakeUpSendMsg();

};

#endif //_EVENTLOOP_H

