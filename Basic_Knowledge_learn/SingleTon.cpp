/*************************************************************************
	> File Name: SingleTon.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 11:36:33 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class HttpServer {
public :
	static HttpServer *getInstance() {
		if (instance == nullptr) {
			instance = new HttpServer();
		}
		return instance;
	}
	
private :
	static HttpServer *instance;
	HttpServer() {}
	HttpServer(const HttpServer &) = delete;
};

HttpServer *HttpServer::instance = nullptr; 

int main() {
	HttpServer *t1 = HttpServer::getInstance();
	HttpServer *t2 = HttpServer::getInstance();
	cout << t1 << " " << t2 << endl;
	return 0;
}
