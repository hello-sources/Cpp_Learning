/*************************************************************************
	> File Name: Default_Delete.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 05 Jan 2021 11:07:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//class T {
//public :
//	T() = delete;
//};

class A {
public :
	A() = default;
	A(const A &) = default; //如果是delete则禁止拷贝构造函数 
	void say() { cout << "hello world" << endl; }
};

int main() {
	A a;
	A b = a;
	b.say();
	return 0;
}
