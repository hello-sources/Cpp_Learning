/*************************************************************************
	> File Name: SingleTon_优化.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 02:10:56 PM CST
 ************************************************************************/

#include <iostream>
#include <mutex>
using namespace std;

class HttpServer {
public :
	static HttpServer *getInstance() {
		if (instance == nullptr) {
			std::unique_lock<std::mutex> lock(m_mutex);
			if (instance == nullptr) {
				instance = new HttpServer();
			}
		}
		return instance;
	}
	
private :
	static HttpServer *instance;
	static std::mutex m_mutex;
	HttpServer() {}
	HttpServer(const HttpServer &) = delete;
	~HttpServer() {}
};

HttpServer *HttpServer::instance = nullptr; 
std::mutex HttpServer::m_mutex;

int main() {
	HttpServer *t1 = HttpServer::getInstance();
	HttpServer *t2 = HttpServer::getInstance();
	cout << t1 << " " << t2 << endl;
	return 0;
}
