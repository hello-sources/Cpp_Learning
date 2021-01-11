/*************************************************************************
	> File Name: Logger.h
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 11:32:15 PM CST
 ************************************************************************/


#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <sstream>
#include <mutex>

namespace haizei {

class LoggerStream : public std::ostringstream {
public :
    LoggerStream() {}
    LoggerStream(const LoggerStream &ls) {}
    ~LoggerStream() {
        output();
    }
private:
    void output() {
        std::unique_lock<std::mutex> lock(m_mutex);
        std::cout << this->str() << std::endl;
        std::cout.flush();
        return ;
    }
    std::mutex m_mutex;
};

class Logger {
    class LoggerStream : public std::ostringstream {
    public :
        LoggerStream(Logger &raw_obj) : raw_obj(raw_obj) {}
        LoggerStream(const LoggerStream &ls) : raw_obj(ls.raw_obj) {}
        ~LoggerStream() {
            output();
        }
    private:
        void output() {
            std::unique_lock<std::mutex> lock(raw_obj.m_mutex);
            std::cout << this->str() << std::endl;
            std::cout.flush();
            return ;
        }
        Logger &raw_obj;
    };
public :
    LoggerStream operator()() {
        return LoggerStream(*this);
    }
private:
    std::mutex m_mutex;
};

}

#endif
