/*************************************************************************
	> File Name: Return_Value.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 06 Jan 2021 07:15:08 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :	
	A() {
		cout << "constructor" << endl;
	}
	A(const A &obj) {
		cout << "copy constructor" << endl;
	}
};

A func() {
	A temp;
	return temp;
}

int main() {
	A a(func());
	
	return 0;
}
