/*************************************************************************
	> File Name: Template.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 03:29:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	cout << "add function : " << sizeof(T) << endl;
	static int i = 0;
	cout << "i : " << ++i << endl;
	return a + b;
} 

template<typename T>
class Array {
public :
	Array(int n) : n(n) {
		this->arr = new T[n];
	}
	T &operator[](int ind) {
		if (ind < 0 || ind >= n) return this->__end;
		return this->arr[ind];
	}
	//<<是一个模板，没有参数的 
	template<typename U> 
	friend ostream &operator<<(ostream &, const Array<U> &);
private :
	T *arr;
	T __end;
	int n;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
	cout << "Class Array : ";
	for (int i = 0; i < a.n; i++) {
		cout << a.arr[i] << " ";
	}
	return out;
} 

int main() {
	cout << add(2, 3) << endl;//显式构造 
	cout << add(2.3, 4.5) << endl;
	cout << add<double>(2.3, 5) << endl; //隐式构造 
	Array<int> a(10);
	Array<double> b(10);
	a[0] = 123;
	a[-123] = 456;
	for (int i = 0; i < 10; i++) {
		b[i] = (rand() % 100) / 100.0;
	}
	cout << a << endl;
	cout << b << endl;
	return 0;
} 
