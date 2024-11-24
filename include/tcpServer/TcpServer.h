/**
 *  * Project C++49期提高
 *   */

#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <string>
#include "ThreadPool.h"
#include "EventLoop.h"
#include "Acceptor.h"

using std::string;

class WebPageReader;
class Dictionary;

class TcpServer {
public:
    using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
    using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;

    /**
     *      * 构造函数
     *           * @param ip 监听的IP地址
     *                * @param port 监听的端口号
     *                     * @param threadNumber 线程池中的线程数量
     *                          * @param queueSize 任务队列的容量
     *                               */
    TcpServer(const string& ip, unsigned short port, size_t threadNumber, size_t queueSize);

    /**
     *      * 启动TcpServer，开始监听连接
     *           */
    void start();

    /**
     *      * 停止TcpServer，关闭监听
     *           */
    void stop();

private:
    ThreadPool _pool;       // 线程池对象，用于处理任务
    Acceptor _acceptor;     // Acceptor对象，用于接受新的连接
    EventLoop _loop;        // EventLoop对象，用于事件循环

    /**
     *      * 连接回调函数
     *           * @param pCon TcpConnection对象指针
     *                */
    void onConnectionCb(const TcpConnectionPtr& pCon);

    /**
     *      * 消息回调函数
     *           * @param pCon TcpConnection对象指针
     *                */
    void onMessageCb(const TcpConnectionPtr& pCon);

    /**
     *      * 关闭回调函数
     *           * @param pCon TcpConnection对象指针
     *                */
    void onCloseCb(const TcpConnectionPtr& pCon);

};

#endif //_TCPSERVER_H

