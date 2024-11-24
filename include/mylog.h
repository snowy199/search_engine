#ifndef __MYLOGGER__
#define __MYLOGGER__
#include <string>
#include <log4cpp/Category.hh>
#include <pthread.h>
#include <cstdarg>

using std::cout;
using std::endl;
using std::string;
using namespace log4cpp;

#define addprefix(msg) string("[").append(__FILE__)\
    .append(":").append(std::to_string(__LINE__))\
.append(":").append(__FUNCTION__).append("()")\
.append("] ").append(msg).c_str() 
#define LogDebug(msg, ...){  \
    mylog::Mylogger::debug(addprefix(msg), ##__VA_ARGS__); \
}
#define LogInfo(msg, ...){   \
    mylog::Mylogger::info(addprefix(msg), ##__VA_ARGS__); \
}
#define LogNotice(msg, ...){   \
    mylog::Mylogger::notice(addprefix(msg), ##__VA_ARGS__); \
}
#define LogWarn(msg, ...){   \
    mylog::Mylogger::warn(addprefix(msg), ##__VA_ARGS__); \
}
#define LogError(msg, ...){   \
    mylog::Mylogger::error(addprefix(msg), ##__VA_ARGS__); \
}
#define LogCrit(msg, ...){   \
    mylog::Mylogger::crit(addprefix(msg), ##__VA_ARGS__); \
}
#define LogAlert(msg, ...){   \
    mylog::Mylogger::alert(addprefix(msg), ##__VA_ARGS__); \
}
#define LogFatal(msg, ...){   \
    mylog::Mylogger::fatal(addprefix(msg), ##__VA_ARGS__); \
}
#define LogEmerg(msg, ...){   \
    mylog::Mylogger::emerg(addprefix(msg), ##__VA_ARGS__); \
}

namespace mylog{
class Mylogger{
public:
    static Mylogger* getInstance(const string& ctgr = "root");


    template<class... ARGS>
        static void debug(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->debug(msg, args...);
            }

        }

    template<class... ARGS>
        static void info(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->info(msg, args...);
            }

        }

    template<class... ARGS>
        static void notice(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->notice(msg, args...);
            }

        }

    template<class... ARGS>
        static void warn(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->warn(msg, args...);
            }

        }

    template<class... ARGS>
        static void error(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->error(msg, args...);
            }

        }

    template<class... ARGS>
        static void crit(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->crit(msg, args...);
            }

        }

    template<class... ARGS>
        static void alert(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->alert(msg, args...);
            }

        }

    template<class... ARGS>
        static void emerg(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->emerg(msg, args...);
            }

        }

    template<class... ARGS>
        static void fatal(const char* msg, ARGS ...args){
            if(_plog != nullptr) {
                _plog->fatal(msg, args...);
            }

        }

    //传入errno，返回报错字符串，封装了线程安全的strerror_r
    static string getErrorMsg(int errorCode);
private:
    Mylogger(){}
    ~Mylogger(){}
    Mylogger(const Mylogger&);
    Mylogger & operator=(const Mylogger&);

    static void init();
    static void destory();

    static string _ctgr;
    static Mylogger* _pInstance;
    static Category* _plog;
    static pthread_once_t _once;
};
}//namespace mylog
#endif
