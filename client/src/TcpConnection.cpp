#include "include/TcpConnection.h"
#include <sstream>
#include <iostream>

using std::ostringstream;

/**
 * TcpConnection implementation
 */


/**
 * @param fd
 */

TcpConnection::TcpConnection(int fd) 
:_socketIO(fd)
,_peerAddr(getPeerAddr())
,_localAddr(getLocalAddr())
{
    std::cout << toString() << " is Connected" << std::endl;

}

TcpConnection::~TcpConnection() {
    std::cout << toString() << " is Closed" << std::endl;
}


/**
 * @param msg
 * @return void
 */
void TcpConnection::send(const string& msg) {
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
 * @return void
 */
bool TcpConnection::isClosed() {
    char buf[4] = {0};
    int ret = recv(_socketIO.fd(), buf, sizeof(buf), MSG_PEEK);
    return ret == 0;
}

string TcpConnection::toString(){
    std::ostringstream oss;
    oss << _localAddr.ip() << ":"
        << _localAddr.port() << " ----> "
        << _peerAddr.ip() << ":"
        << _peerAddr.port();
    return oss.str();

}



/**
 * @return InetAddress
 */
InetAddress TcpConnection::getLocalAddr() {

    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getsockname(_socketIO.fd(), (struct sockaddr*)&addr, &len);
    if(ret == -1){
        perror("getsockname");
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
        perror("getpeername");
    }

    return InetAddress(addr);

}
