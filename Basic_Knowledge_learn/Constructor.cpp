/*************************************************************************
	> File Name: Constructor.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 05 Jan 2021 10:03:16 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
	A() : next(nullptr) {//只有走到变量定义的时候，才能调用默认构造函数
		cout << this <<" default constructor" << endl;
	}
	A(A *obj) {
		this->next = obj;
		this->next->arr = new int[1000];
	}
	A(int n) : next(nullptr) {
		cout << this << " an int constructor" << endl;
		x = n, y = n;
	} 
	A(const A &obj) : next(nullptr) {//必须传引用 
		cout << this << " copy constructor" << endl; 
		this->x = obj.x, this->y = obj.y;
	} 
	void output() {
		cout << this->x << " " << this->y << endl; 
	}
	void operator=(int n) {
		cout << "operator =" << endl;
		x = n, y = n;
	} 
	int x, y;
	int *arr;
	A *next;	
	~A() {//析构函数栈空间，系统栈 
		if (this->next) {
			delete this->next->arr; 
		}
		cout << this << " destructor" << endl;
	}
};

void func(int &x) {//引用，相当于变量的别名 
	x += 5;
} 

A aa;//构造顺序与析构顺序相反 
A bb(&aa);
A cc(&bb); 

int main() {
	int n = 7;
	func(n);
	cout << n << endl;
	cout << "pre postition" << endl;
	A a; 
	A b = 8;//相当于类型转换，也是相当于一个传入int参数 
	A c(a);
	cout << "a = " << &a << endl;
	cout << "b = " << &b << endl;
	cout << "c = " << &c << endl;
	cout << "aa = " << &aa << endl;
	cout << "bb = " << &bb << endl;
	cout << "cc = " << &cc << endl;
	b.output();
	b = 6;//默认情况下为有参构造函数 
	b.output();
	cout << "next position" << endl;
	return 0;
}
