/*************************************************************************
	> File Name: 三五法则.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 06 Jan 2021 07:10:35 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
	A() : z(0), w(x) {}
	A(int x, int y) : x(x), y(y), z(8), w(this->x) {}
//	A(const A &) = default;
	A(const A &a) : z(a.z), w(x) {
		this->x = a.x;
		this->y = a.y;
		//this->z = b.z;否则出错 
	}
	void say() { cout << "hello world" << endl; }
private :
	int *arr;
	int x, y; 
	const int z;
	int &w;
}; 

int main() {
	A *p = new A();
	A a(3, 4);
	A b = a; 
	return 0;
}
