/*************************************************************************
	> File Name: Override.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 04:07:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
	virtual void func1()  {
		cout << "Class A func one" << endl;
	}
	void funcl() {
		cout << "Class A func L" << endl;
	}
};

struct B : A {
	void func1() override {
		cout << "Class B funcl" << endl;
	}
};

int main() {
	B b;
	A *a = &b;
	a->func1();
	
	return 0;
}
