#include "tcpServer/Socket.h"

/**
 * Socket implementation
 */


Socket::Socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    error_check(sockfd, -1, "socket");
    _fd = sockfd;
}

/**
 * @param fd
 */
Socket::Socket(int fd) 
:_fd(fd){

}

Socket::~Socket() {
    ::close(_fd);
}

/**
 * @return int
 */
int Socket::fd() {
    return _fd;
}
