/*************************************************************************
	> File Name: Virtual_Table.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 12:36:03 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public :
	Animal() {
		x = 8827, y = 65123;
	}
	virtual void say(int x) {
		cout << "I don't know how to say" << endl;
	}
	virtual void run() {
		cout << "I don't know how to run" << endl;
	}
protected :
	int x, y;
};

class Cat : public Animal {
public :
	void say(int x) override {
		cout << this << endl;
		cout << this->x << " " << this->y << endl;
		cout << x << endl;
		cout << "miao~ miao~ miao~" << endl;
	}
	void run() override {
		cout << "I can run with four legs" << endl;
	}
};

void output_raw_data(void *q, int n) {
	printf("%p : ", q);
	unsigned char *p = (unsigned char *)q;
	for (int i = 0; i < n; i++) {
		printf("%02X ", p[i]);
	}
	printf("\n");
	return ;
}

typedef void (*func)(void *, int x);

int main() {
	Cat a, b;
	output_raw_data(&a, sizeof(a));
	output_raw_data(&b, sizeof(b));
	((func **)(&a))[0][0](&a, 123);
	return 0;
} 
