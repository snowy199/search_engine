#include "tcpServer/TcpConnection.h"
#include "tcpServer/EventLoop.h"
#include "mylog.h"
/**
 * TcpConnection implementation
 */


/**
 * @param fd
 */
TcpConnection::TcpConnection(int fd, EventLoop& loop) 
    :_loop(loop)
    ,_socketIO(fd)
    ,_localAddr(getLocalAddr())
     ,_peerAddr(getPeerAddr())
{}

TcpConnection::~TcpConnection() {

}

/**
 * @param msg
 * @return void
 */
void TcpConnection::send(const string & msg) {
    _socketIO.write(msg);
    return;
}

/**
 * @return string
 */
string TcpConnection::receive() {
    return _socketIO.receive();
}

/**
 * @return string
 */
string TcpConnection::toString() {
    std::ostringstream oss;
    oss << _localAddr.ip() << ":"
        << _localAddr.port() << " ----> "
        << _peerAddr.ip() << ":"
        << _peerAddr.port();
    return oss.str();
}

/**
 * @return bool
 */
bool TcpConnection::isClosed() {
    char buf[4] = {0};
    int ret = recv(_socketIO.fd(), buf, sizeof(buf), MSG_PEEK);
    return ret == 0;
}

void TcpConnection::setCallback(TcpConnectionCallback & connection, TcpConnectionCallback & message, TcpConnectionCallback & closeCb){
    _onConnectionCb = connection;
    _onMessageCb = message;
    _onCloseCb = closeCb;
}
/**
 * @return void
 */
void TcpConnection::handleNewConnectionCallback() {
    if(!_onConnectionCb) return;
    _onConnectionCb(shared_from_this());
    return;
}

/**
 * @return void
 */
void TcpConnection::handleMessageCallabck() {
    if(!_onMessageCb) return;
    _onMessageCb(shared_from_this());
    return;
}

/**
 * @return void
 */
void TcpConnection::hanleCloseCallback() {
    if(!_onCloseCb) return;
    _onCloseCb(shared_from_this());
    return;
}

void TcpConnection::addSendBc(const string & msg){
    _loop.addSendBc(std::bind(&TcpConnection::send, this, msg));
}
/**
 * @return InetAddress
 */
using Mylog = mylog::Mylogger;
InetAddress TcpConnection::getLocalAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getsockname(_socketIO.fd(), (struct sockaddr*)&addr, &len);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("getsockname: %s", error.c_str());
    }

    return InetAddress(addr);
}

/**
 * @return InetAddress
 */
InetAddress TcpConnection::getPeerAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getpeername(_socketIO.fd(), (struct sockaddr*)&addr, &len);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("getpeername: %s", error.c_str());
    }

    return InetAddress(addr);
}
