/*************************************************************************
	> File Name: Thread_Pool.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 11 Jan 2021 10:21:37 PM CST
 ************************************************************************/

#include <iostream>
#include "Thread_Pool.h"
#include <functional>
#include <chrono>
using namespace std;

void func(int x, int &n) {
	n += 2;
	cout << "func : " << x << " " << n << endl;
}

int main() {
	int n = 123;
	haizei::Task t(func, 23, ref(n));
	t.run();
	cout << n << endl;
	haizei::thread_pool tp(2);
	tp.start();
	for (int i = 0; i < 10; i++) {
		tp.add_one_task(func, i, ref(n));
	}
	cout << "add task done" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "tp stop" << endl;
	tp.stop();
	return 0;
}
