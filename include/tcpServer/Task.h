/**
 *  * Project SearchEngine
 *   */

#ifndef _TASK_H
#define _TASK_H

#include <memory>
#include <string>

class TcpConnection;

using std::shared_ptr;
using TcpConnectionPtr = shared_ptr<TcpConnection>;
using std::string;

class Task {
public:
    /**
     *      * 构造函数
     *           * @param pCon TcpConnection 的智能指针
     *                * @param msg 任务消息字符串
     *                     */
    Task(TcpConnectionPtr pCon, const string& msg);

    /**
     *      * 执行任务
     *           * @param tNum 线程编号
     *                */
    void pocess(int tNum);

private:
    TcpConnectionPtr _pCon;  // TcpConnection 的智能指针
    string _msg;             // 任务消息字符串

    /**
     *      * 判断字符串是否为英文
     *           * @param msg 待判断的字符串
     *                * @return 判断结果，如果是英文返回 true，否则返回 false
     *                     */
    bool isEnglish(const string& msg);

    /**
     *      * 判断字符串是否非英文
     *           * @param msg 待判断的字符串
     *                * @return 判断结果，如果非英文返回 true，否则返回 false
     *                     */
    bool isNotEnglish(const string& msg);

    /**
     *      * 封装消息
     *           * @param msgId 消息ID
     *                * @param msg 消息内容
     *                     * @return 封装后的消息字符串
     *                          */
    string packMessage(const string& msgId, const string& msg);

};

#endif //_TASK_H

