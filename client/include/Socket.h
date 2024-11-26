/**
 * Project SearchEngine
 */


#ifndef _SOCKET_H
#define _SOCKET_H
#include <sys/socket.h>
#include <string>
#include <unistd.h>

class Socket {
public: 
    
Socket();
Socket(int fd);    
~Socket();
    
int fd();
private: 
    int _fd;
};

#endif //_SOCKET_H
