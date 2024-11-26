
#include "tcpServer/TcpServer.h"
#include "tcpServer/TcpConnection.h"
#include "tcpServer/Task.h"
#include "webPage/WebPageReader.h"
#include "dict/dictionary.h"
#include "mylog.h"


/**
 * TcpServer implementation
 */

/**
 * @param ip
 * @param port
 * @param threadNumber
 * @param queueSize
 */
TcpServer::TcpServer(const string& ip, unsigned short port, 
                     size_t threadNumber, size_t queueSize)
:_pool(threadNumber, queueSize)
,_acceptor(ip, port)
,_loop(_acceptor)
{
}

/**
 * @return void
 */
using namespace std::placeholders;
void TcpServer::start() {
    _pool.start();
    _loop.setCallback(std::bind(&TcpServer::onConnectionCb, this, _1)
                      ,std::bind(&TcpServer::onMessageCb, this, _1)
                      ,std::bind(&TcpServer::onCloseCb, this, _1));

    _loop.loop();
    return;
}

/**
 * @return void
 */
void TcpServer::stop() {
    _pool.shutdown();
    _loop.unloop();
    return;
}


void TcpServer::onConnectionCb(const TcpConnectionPtr & pCon){
    LogInfo("%s has connected", pCon->toString().c_str());
}
void TcpServer::onMessageCb(const TcpConnectionPtr & pCon){
    string msg = pCon->receive();

    Task task(pCon, msg);
    _pool.addTask(std::bind(&Task::pocess, task, _1));


}
void TcpServer::onCloseCb(const TcpConnectionPtr & pCon){
    LogInfo("%s has closed", pCon->toString().c_str());
}

