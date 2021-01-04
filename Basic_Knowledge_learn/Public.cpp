/*************************************************************************
	> File Name: Public.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 04 Jan 2021 10:25:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
	int x, y;
	int echo() {
		cout << "hello world!" << endl;
		return 0;
	}
};

class B {
public :
	void set_xy(int x, int y) {
		cout << this << endl;
		this->x = x, this->y = y;
	}
	int echo() {
		cout << "hello world!" << endl;
		cout << x << " " << y << endl; 
		return 0;
	}
private :
	int x, y;
};

int main() {
	A a;
	B b;
	a.x = 3, a.y = 2;
//	b.x = 3, b.y = 2;
	b.set_xy(3, 2);
	cout << &b << endl;
	cout << a.x << " " << a.y << endl;
//	cout << b.x << " " << b.y << endl;
	b.echo();
	return 0;
} 
