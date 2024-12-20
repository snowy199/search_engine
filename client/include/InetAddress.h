/**
 * Project SearchEngine
 */


#ifndef _INETADDRESS_H
#define _INETADDRESS_H

#include <arpa/inet.h>
#include <string>

using std::string;

class InetAddress {
public: 
    
/**
 * @param ip
 * @param port
 */
InetAddress(const string & ip, unsigned short port);
InetAddress(const struct sockaddr_in & addr);
    
~InetAddress();
    
string ip();
    
unsigned short port();
    
struct sockaddr_in * getInetAddrPtr();
private: 
    struct sockaddr_in _addr;
};

#endif //_INETADDRESS_H
