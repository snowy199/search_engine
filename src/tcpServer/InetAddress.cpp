#include "tcpServer/InetAddress.h"

/**
 * InetAddress implementation
 */


/**
 * @param ip
 * @param port
 */
InetAddress::InetAddress(const string & ip, unsigned short port) 
:_addr()
{
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(port);
    inet_aton(ip.c_str(), &_addr.sin_addr);
}

/**
 * @param addr
 */
InetAddress::InetAddress(const struct sockaddr_in & addr) 
:_addr(addr){

}

InetAddress::~InetAddress() {

}

/**
 * @return string
 */
string InetAddress::ip() {
    return inet_ntoa(_addr.sin_addr);
}

/**
 * @return unsigned short
 */
unsigned short InetAddress::port() {
    return _addr.sin_port;
}

/**
 * @return struct sockaddr_in *
 */
struct sockaddr_in * InetAddress::getSockaddrPtr() {
    return &_addr;
}


