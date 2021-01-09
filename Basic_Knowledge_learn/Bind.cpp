/*************************************************************************
	> File Name: Bind.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 11:10:24 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <cstdlib>
using namespace std;

void func(int x, int y, int z) {
	cout << x + y << " is a number" << endl;
	cout << z << " is a number" << endl;
}

struct A {
	void say() {
		cout << this << " : saying" << endl;
	}
	void run() {
		cout << "hello world" << endl;
	}
};

void count_function_times(function<void()> &p, int &cnt) {
	p();
	cnt += 1;
	return ;
}

int main() {
	function<void(int, int)> f1 = bind(func, 123, std::placeholders::_2,std::placeholders::_1);
	f1(100, 456);
	f1(200, 789);
	A a;
	cout << &a << endl;
	function<void()> f2 = bind(&A::say, ref(a));
	f2();
	int cnt = 0;
	function<void()> f3 = bind(&A::run, ref(a));
	function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
	for(int i = 0; i < rand() % 10; i++) {
		f4();
	}
	cout << cnt << endl;
	return 0;
}
