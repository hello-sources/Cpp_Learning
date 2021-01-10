/*************************************************************************
	> File Name: Rvalue.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 09:25:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void f2(int &x) {
	cout << "in function f2 : " << x << " is left value" << endl;
}

void f2(int &&x) {
	cout << "in function f2 : " << x << " is right value" << endl;
	return ;
} 

void f(int &x) {
	cout << x << " is left value" << endl;
	f2(forward<int &>(x));
	return ;
}

void f(int &&x) {
	cout << x << " is right value" << endl;
	f2(forward<int &&>(x));
	return ; 
}

class A {
public :
	A(int n = 10) : n(n) {
		arr = new int[this->n];
		for (int i = 0; i < this->n; i++) arr[i] = i;
	}	
	A(const A &obj) : n(obj.n) {
		cout << "copy constructor" << endl; 
		this->arr = new int[n];
		for (int i = 0; i < n; i++) {
			this->arr[i] = obj.arr[i];
		}
	}
	A(A &&obj) {
		cout << "move constructor" << endl;
		this->n = obj.n;
		this->arr = obj.arr;
		obj.arr = nullptr;
	}
	A operator+(const A &obj) {
		A temp(this->n + obj.n);
		for (int i = 0; i < this->n; i++) temp.arr[i] = arr[i];
		for (int i = 0; i < obj.n; i++) temp.arr[i + this->n] = obj.arr[i];
		return temp;
	}
	void output() {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return ;
	}
	~A() {
		cout << "destructor" << endl;
		delete[] arr;
	}
private :
	int *arr;
	int n;
};

int main() {
	int n = 123;
	cout << (++n)++ << endl;	
	cout << n << endl;
	f(n++);
	f(move(++n));
	A *p = new A();
	A a = move(*p);
	delete p;
	return 0;
} 
