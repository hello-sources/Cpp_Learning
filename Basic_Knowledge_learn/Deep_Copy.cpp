/*************************************************************************
	> File Name: Deep_Copy.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 06 Jan 2021 07:14:10 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
	A() {
		this->arr = new int[100];
	}
	A(const A &obj) : x(obj.x), y(obj.y) {
		this->arr = new int[100];
		memcpy(this->arr, obj.arr, sizeof(int) * 100);
	}
	int *arr;
	int x, y;
}; 

int main() {
	A a;
	a.x = 3, a.y = 6;
	a.arr[0] = 123;
	A b = a;
	b.arr[0] = 456;
	cout << a.arr[0] << " " << b.arr[0] << endl;
	cout << b.x << " " << b.y << endl;
	b.x = 6;
	cout << a.x << " " << a.y << endl;
	cout << b.x << " " << b.y << endl;
	return 0;
}
