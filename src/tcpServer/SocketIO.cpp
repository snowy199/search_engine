#include "tcpServer/SocketIO.h"
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include "mylog.h"
/**
 * SocketIO implementation
 */

using Mylog = mylog::Mylogger;
/**
 * @param fd
 */
SocketIO::SocketIO(int fd) 
    :_fd(fd){

    }

SocketIO::~SocketIO() {
    ::close(_fd);
}

string SocketIO::receive(){
    //接收即将接收的字符串的长度
    int len = 0;
    int ret = recv(_fd, &len, sizeof(int), 0);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("recv: %s", error.c_str());
        return "";
    }

    //接收字符串存入buf
    char* buf = new char[len + 1]();
    ret = readn(buf, len);
    if(ret < 0){
        return "";
    }else if(ret < len){
        LogError("Receive interrupt");
    }
        

    //用buf初始化返回字符串，释放buf
    string res(buf);
    delete []buf;

    return res;
}

int SocketIO::write(const string & str){
    int ret = writen(str.c_str(), str.size());
    if(ret == -1){
        return -1;
    }else if(ret < (int)str.size()){
        LogError("Send interrupt");
    }
    return ret;
}      

int SocketIO::fd(){
    return _fd;
}
/**
 * @param buf
 * @param len
 * @return int
 */
int SocketIO::readn(char* buf, int len) {
    bzero(buf, len);
    int recvedLen = 0;
    while(recvedLen < len){
        int ret = recv(_fd, buf + recvedLen, len - recvedLen, 0);
        if(ret == -1 && errno == EINTR){
            continue;
        }else if(ret == -1){
            string error = Mylog::getErrorMsg(errno);
            LogError("recv: %s", error.c_str());
            return -1;
        }else if(ret == 0){
            break;
        }
        else{
            recvedLen += ret;
        }
    }
    return recvedLen;

}

/**
 * @param buf
 * @param len
 * @return int
 */
int SocketIO::writen(const char* buf, int len) {
    int ret = send(_fd, &len, sizeof(int), MSG_NOSIGNAL);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("send: %s", error.c_str());
        return -1;
    }

    int sendedLen = 0;
    while(sendedLen < len){
        int ret = send(_fd, buf + sendedLen, len - sendedLen, MSG_NOSIGNAL);
        if(ret == -1 && errno == EINTR){
            continue;
        }else if(ret == -1){
            string error = Mylog::getErrorMsg(errno);
            LogError("send: %s", error.c_str());
            return -1;
        }else if(ret == 0){
            break;
        }else{
            sendedLen += ret;
        }
    }
    return sendedLen;
}
