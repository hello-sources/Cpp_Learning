/*************************************************************************
	> File Name: Static_Const_Method.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 06 Jan 2021 07:12:45 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
	A(int x) {
		cout << "class A's constructor" << endl;
	}
}; 

class Point {
public :
	Point ();
	// C++中若我们实现有参构造函数,则默认构造函数(无参)就会被删除 
	Point(int x, int y);
	//const说明不改内部成员属性
	int x() const;//读取x,说明是常量方法，不改内部成员属性 
	int y() const;//读取y,说明是常量方法，不改内部成员属性
	int x_cnt() const; 
	void set_x(int x); //修改x 
	void set_y(int y); //修改y 
	static int output_cnt();
	~Point();
	
private :
	static int point_cnt;
	int __x, __y;//成员属性必须为private
	mutable int __x_cnt; //使得当前成员属性能够被修改 
	A __a;
};

int Point::point_cnt = 0;//类属性的定义 

int Point::output_cnt() {
	return Point::point_cnt;
}

Point::Point() : __x_cnt(0), __a(2) {//初始化列表，相当于调用成员属性的构造函数 
	Point::point_cnt += 1; 
}
Point::Point(int x, int y) : 
	__x(x), __y(y),
	__x_cnt(0), __a(4) {
	Point::point_cnt += 1;
}

Point::~Point() {
	Point::point_cnt -= 1;
} 

int Point::x() const {//成员方法的声明和定义分开 
	this->__x_cnt += 1;
	return this->__x;
}

int Point::y() const {
	return this->__y;
}

int Point::x_cnt() const {
	return this->__x_cnt;
}

void Point::set_x(int x) {
	this->__x = x;
}

void Point::set_y(int y) {
	this->__y = y;
}

void func() {
	Point c, d;
	cout << "func : " << Point::output_cnt() << endl;
	return ;
}

int main() {
	Point a(2, 3), b;
	const Point c(3, 4);
	cout << a.x() << " " << a.y() << endl; 
	cout << c.x() << " " << c.y() << endl;
	cout << c.x() << " " << c.y() << endl;
	cout << a.x_cnt() << " " << b.x_cnt() << " " << c.x_cnt() << endl;
	cout << "before func : " << Point::output_cnt() << endl;
	func();
	cout << "after func : " << Point::output_cnt() << endl;
	return 0;
}
