/*************************************************************************
	> File Name: Logger_Main.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 11:33:00 PM CST
 ************************************************************************/

#include <iostream>
#include "Logger.h"
#include "Thread_Pool.h" 
using namespace std;

void func1() {
	cout << "1" << "2" << "3" << "4" << "5" << "6" << endl;
	return ;
}

void func2(haizei::Logger &log) {
	log() << "1" << "2" << "3" << "4" << "5" << "6";
	return ;
}

int main() {
	haizei::thread_pool tp(10);
	tp.start();
	for (int i = 1; i <= 100; i++) {
		tp.add_one_task(func1);
	} 
	std::this_thread::sleep_for(std::chrono::seconds(2));
	tp.stop();
	cout << "cout done" << endl;
	cout.flush();
	tp.start();
	haizei::Logger log;
	for (int i = 1; i <= 20; i++) {
		tp.add_one_task(func2, ref(log));
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));
	tp.stop();
	cout << "log() done" << endl;
	return 0;
} 
