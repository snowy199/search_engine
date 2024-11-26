/**
 * Project SearchEngine
 */


#ifndef _SOCKETIO_H
#define _SOCKETIO_H
#include <string>

using std::string;

class SocketIO {
public: 
    
/**
 * @param fd
 */
SocketIO(int fd);
    
~SocketIO();
    
string receive();
int write(const string & str);

int fd();
/**
 * @param buf
 * @param len
 */
int readn(char* buf, int len);
    
/**
 * @param buf
 * @param len
 */
int writen(const char* buf, int len);
private: 
    int _fd;
};

#endif //_SOCKETIO_H
