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

#define LOG_TRACE haizei::haizei_log(__FILE__, __func__, __LINE__)

namespace haizei {

/*
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
*/

class Logger {
    class LoggerStream : public std::ostringstream {
    public :
        LoggerStream(
			const char *file_name,
			const char *func_name,
			int line_no,
			Logger &raw_obj) : 
			raw_obj(raw_obj), 
			file_name(file_name),
			func_name(func_name),
			line_no(line_no) {
				std::ostringstream &now = *this;
            	now << "[" << file_name << "project]";
            	now << " [" << func_name << "] ";
			}
        LoggerStream(const LoggerStream &ls) : raw_obj(ls.raw_obj) {}
        ~LoggerStream() {
            output();
        }
    private:
        void output() {
            std::unique_lock<std::mutex> lock(raw_obj.m_mutex);
            std::ostringstream &now = *this;
            now << " (" << line_no << ")";
			std::cout << this->str() << std::endl;
            std::cout.flush();
            return ;
        }
        Logger &raw_obj;
        const char *file_name;
        const char *func_name;
        int line_no; 
    };
public :
    LoggerStream operator()(const char *file_name, const char *func_name, int line_no) {
        return LoggerStream(file_name, func_name, line_no, *this);
    }
private:
    std::mutex m_mutex;
};

Logger haizei_log;

}

#endif
