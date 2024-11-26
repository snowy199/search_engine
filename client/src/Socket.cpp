#include "include/Socket.h"

/**
 * Socket implementation
 */


Socket::Socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("socket");
    }
    _fd = sockfd;
}

Socket::Socket(int fd)
:_fd(fd){}

Socket::~Socket() {
}

/**
 * @return int
 */
int Socket::fd() {
    return _fd;
}
