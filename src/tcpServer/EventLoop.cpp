#include "tcpServer/EventLoop.h"
#include "tcpServer/Acceptor.h"        
#include "tcpServer/TcpConnection.h"
#include "mylog.h"


/**
 * EventLoop implementation
 */
using Mylog = mylog::Mylogger;

/**
 * @param acceptor
 */
EventLoop::EventLoop(Acceptor & acceptor) 
:_epfd(createEpollFd())
,_evfd(createEventFd())
,_isLooping(false)
,_acceptor(acceptor)
,_evtList(1024)
,_conns()
,_mutex()
,_sendTasks()
{
    _acceptor.ready();
    addEpollReadFd(acceptor.fd());
    addEpollReadFd(_evfd);
}

EventLoop::~EventLoop() {
    close(_epfd);
    close(_evfd);
}

void EventLoop::setCallback(TcpConnectionCallback && connection, TcpConnectionCallback && message, TcpConnectionCallback && closeCb){
    _onConnectionCb = std::move(connection);
    _onMessageCb = std::move(message);
    _onCloseCb = std::move(closeCb);
}
/**
 * @return void
 */
void EventLoop::loop() {
    _isLooping = true;
    while(_isLooping){
        waitEpollFd();
    }
    return;
}

/**
 * @return void
 */
void EventLoop::unloop() {
    _isLooping = false;
    return;
}

void EventLoop::addSendBc(SendCb && cb){
    _mutex.lock();
    _sendTasks.push_back(cb);
    _mutex.unlock();
    
    wakeUpSendMsg();
}
/**
 * @return void
 */
void EventLoop::waitEpollFd() {
    int readyNum = epoll_wait(_epfd, &*_evtList.begin(), _evtList.size(), 5000);
    if(readyNum == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("epoll_wait: %s", error.c_str());
    }else if(readyNum == 0){
        cout << ">>epoll_wait_timeout\n";
    }else{
        //如果就绪队列过多可能超过容量，要扩容
        if((unsigned long)readyNum == _evtList.size()){
            _evtList.resize(2*_evtList.size());
        }

        for(int idx = 0; idx < readyNum; ++idx){
            int fd = _evtList[idx].data.fd;
            if(fd == _acceptor.fd()){
                if(_evtList[idx].events & EPOLLIN){
                    handleNewConnection();
                }
            }else if(fd == _evfd){
                if(_evtList[idx].events & EPOLLIN){
                    handleRead();
                    sendMsg();
                }
            }else{
                if(_evtList[idx].events & EPOLLIN){
                    handleMessage(fd);
                }
            }
        }
    }
    return;
}

/**
 * @return void
 */
void EventLoop::handleNewConnection() {
    int fd = _acceptor.accept();
    if(fd == -1){
        return;
    }
    TcpConnectionPtr ptcp(new TcpConnection(fd, *this));
    
    _conns.insert({fd, ptcp});
    addEpollReadFd(fd);
    ptcp->setCallback(_onConnectionCb, _onMessageCb, _onCloseCb);
    
    ptcp->handleNewConnectionCallback();
    return;
}

/**
 * @param fd
 * @return void
 */
void EventLoop::handleMessage(int fd) {
    auto it = _conns.find(fd);
    if(it == _conns.end()){
        cout << "Connection does not exit\n";
    }else{
        if(it->second->isClosed()){
            it->second->hanleCloseCallback();
            delEpollReadFd(fd);
            _conns.erase(it);
        }else{
            it->second->handleMessageCallabck();
        }
    }
    return;
}

/**
 * @return int
 */
int EventLoop::createEpollFd() {
    int epfd = epoll_create(1);
    if(epfd == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("epoll_create: %s", error.c_str());
    }
    return epfd;
}

int EventLoop::createEventFd(){
    int ret = eventfd(0, 0);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("eventfd: %s", error.c_str());
    }
    return ret;
}
/**
 * @param fd
 * @return void
 */
void EventLoop::addEpollReadFd(int fd) {
    struct epoll_event event;
    bzero(&event, sizeof(epoll_event));
    event.data.fd = fd;
    event.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &event);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("epoll_ctl_add: %s", error.c_str());
    }
    return;
}

/**
 * @param fd
 * @return void
 */
void EventLoop::delEpollReadFd(int fd) {
    struct epoll_event event;
    bzero(&event, sizeof(epoll_event));
    event.data.fd = fd;
    event.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &event);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("epoll_ctl_del: %s", error.c_str());
    }
    return;
}

void EventLoop::sendMsg(){
    vector<SendCb> tmp;
    _mutex.lock();
    tmp.swap(_sendTasks);
    _mutex.unlock();
    for(auto it : tmp){
        it();
    }
}

void EventLoop::handleRead(){
    uint64_t value;
    ssize_t sret = read(_evfd, &value, sizeof(uint64_t));
    if(sret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("read uint64_t: %s", error.c_str());
    }
    return;
}

void EventLoop::wakeUpSendMsg(){
    uint64_t value = 1;
    ssize_t ret = write(_evfd, &value, sizeof(uint64_t));
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("write uint64_t: %s", error.c_str());
    }
    return;
}
