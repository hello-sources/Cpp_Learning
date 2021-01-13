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
#include <map>
#include <string>

#define LOG_TRACE(level) haizei::haizei_log(__FILE__, __func__, __LINE__, level)
#define LOG_INFO LOG_TRACE(haizei::LogLevel::INFO)
#define LOG_DEBUG LOG_TRACE(haizei::LogLevel::DEBUG)
#define LOG_WARN LOG_TRACE(haizei::LogLevel::WARN)
#define LOG_ERROR LOG_TRACE(haizei::LogLevel::ERROR)
#define LOG_SET(levels) haizei::Logger::set_level(levels)


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

class LogLevel {
public : 
	static const int INFO;
	static const int DEBUG;
	static const int WARN;
	static const int ERROR;
};

const int LogLevel::INFO = 1;
const int LogLevel::DEBUG = 2;
const int LogLevel::WARN = 4;
const int LogLevel::ERROR = 8;

std::map<int, std::string> LogLevelStr = {
	{LogLevel::INFO, "INFO"},
	{LogLevel::DEBUG, "DEBUG"},
	{LogLevel::WARN, "WARN"},
	{LogLevel::ERROR, "ERROR"}
};

class Logger {
    class LoggerStream : public std::ostringstream {
    public :
        LoggerStream(
			const char *file_name,
			const char *func_name,
			int line_no,
			Logger &raw_obj,
			int l
			) : 
			raw_obj(raw_obj), 
			line_no(line_no),
			flag(1) {
				std::ostringstream &now = *this;
            	now << "[" << file_name << "project]";
            	now << " [" << func_name << "] ";
            	now << " [" << LogLevelStr[l] << "] ";
            	flag = Logger::logger_level_conf & l;
			}
        LoggerStream(const LoggerStream &ls) : raw_obj(ls.raw_obj) {}
        ~LoggerStream() {
            if (flag) output();
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
        int line_no, flag;      
    };
public :
    LoggerStream operator()(const char *file_name, const char *func_name, int line_no, int l) {
        return LoggerStream(file_name, func_name, line_no, *this, l);
    }
	static void set_level(int levels) {
		Logger::logger_level_conf = levels;
		return ;
	}
private:
    std::mutex m_mutex;
    static int logger_level_conf; 
};

int Logger::logger_level_conf = 0;

Logger haizei_log;

}

#endif
