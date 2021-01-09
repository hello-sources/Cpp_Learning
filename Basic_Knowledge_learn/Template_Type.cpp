/*************************************************************************
	> File Name: Template_Type.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 10:21:42 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

template<typename T>
void my_swap(T &&a, T &&b) {
	typename remove_reference<T>::type c;
	c = a;
	a = b;
	b = c;
	return ;
} 

template<typename T>
void add(T &&a, T &&b) {
	a += 3;
	b += 4;
	return ;
}

void func(void (*p)(int &, int &), int &a, int &b) {
	p(a, b);
	return ;
}


int main() {
	int a = 123, b = 456;
	cout << a << " " << b << endl;
	my_swap(a, b);
	cout << a << " " << b << endl;
	my_swap(move(a), move(b));
	cout << a << " " << b << endl;
	func(add, a, b);
	cout << a << " " << b << endl;
	return 0;
}
