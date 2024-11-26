/**
 * Project SearchEngine
 */


#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H
#include <string>
#include "SocketIO.h"
#include "InetAddress.h"

using std::string;

class TcpConnection {
public: 
    
/**
 * @param fd
 */
explicit TcpConnection(int fd);
    
~TcpConnection();
    
bool isClosed();

string toString();
    
/**
 * @param msg
 */
void send(const string& msg);
    
string receive();
private: 
    SocketIO _socketIO;
    InetAddress _peerAddr;
    InetAddress _localAddr;
    
InetAddress getLocalAddr();
    
InetAddress getPeerAddr();
};

#endif //_TCPCONNECTION_H
