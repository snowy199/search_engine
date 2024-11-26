/**
 * Project SearchEngine
 */


#include "Connection.h"

/**
 * Connection implementation
 */


/**
 * @param ip
 * @param port
 */
Connection::Connection(const string & ip, unsigned short port) 
:_sock()
,_addr(ip,port){
    int ret = connect(_sock.fd(), (struct sockaddr*)_addr.getInetAddrPtr(), sizeof(_addr));
    if(ret == -1){
        perror("connect");
        exit(1);
    }
}

Connection::~Connection() {

}


/**
 * @return int
 */
int Connection::fd() {
    return _sock.fd();
}
