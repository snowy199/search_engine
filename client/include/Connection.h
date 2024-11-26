/**
 * Project SearchEngine
 */


#ifndef _CONNECTION_H
#define _CONNECTION_H
#include "Socket.h"
#include "InetAddress.h"

class Connection {
public: 
    
/**
 * @param ip
 * @param port
 */
Connection(const string & ip, unsigned short port);
    
~Connection();
    
    
int fd();
private: 
    Socket _sock;
    InetAddress _addr;
};

#endif //_CONNECTION_H
