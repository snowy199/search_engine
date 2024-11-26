#include "tcpServer/Acceptor.h"

/**
 * Acceptor implementation
 */


/**
 * @param ip
 * @param port
 */
Acceptor::Acceptor(const string & ip, unsigned short port) 
:_sock()
,_addr(ip,port)
{

}

Acceptor::~Acceptor() {

}

/**
 * @return void
 */
void Acceptor::ready() {
    setReuseAddr();
    setReusePort();
    bind();
    listen();
}

/**
 * @return int
 */
int Acceptor::accept() {
    socklen_t len = sizeof(sockaddr);
    int netfd = ::accept(_sock.fd(), (struct sockaddr*)_addr.getSockaddrPtr(), &len);
    error_check(netfd, -1, "accept");
    return netfd;
}

int Acceptor::fd(){
    return _sock.fd();
} 
/**
 * @return void
 */
void Acceptor::setReuseAddr() {
    int opval = 1;
    int ret = setsockopt(_sock.fd(), SOL_SOCKET, SO_REUSEADDR, &opval, sizeof(opval));
    error_check(ret, -1, "setsockopt reuseAddr");
    return;
}

/**
 * @return void
 */
void Acceptor::setReusePort() {
    int opval = 1;
    int ret = setsockopt(_sock.fd(), SOL_SOCKET, SO_REUSEPORT, &opval, sizeof(opval));
    error_check(ret, -1, "setsockopt reusePort");
    return;
}

/**
 * @return void
 */
void Acceptor::bind() {
    int ret = ::bind(_sock.fd(), (struct sockaddr*)_addr.getSockaddrPtr(), sizeof(sockaddr));
    error_check(ret, -1, "bind");
    return;
}

/**
 * @return void
 */
void Acceptor::listen() {
    int ret = ::listen(_sock.fd(), 128);
    error_check(ret, -1, "listen");
    return;
}
