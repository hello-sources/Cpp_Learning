/*************************************************************************
	> File Name: Template_Add.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 09:55:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct A {
	A() = delete;
	A(int x) : x(x) {}
	int operator+(int x) {
		return x + this->x + 0.001;
	}
	int x;
};

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
	return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(add(*a, *b)) {
	return add(*a, *b);
}

auto func(int x)  -> int {
	return 2 * x;
}

int main() {
	cout << add(2, 3) << endl;
	cout << add(2.3, 4.5) << endl;
	cout << add(2, 3.4) << endl;
	cout << add(3.4, 2) << endl;
	int a = 12;
	double b = 45.7;
	decltype(a + b) c;
	cout << sizeof(c) << endl;
	A d(6);
	cout << add(d, 4) << endl;
	cout << func(4) << endl;
	cout << add(a, b) << endl;
	cout << add(&a, &b) << endl;
	return 0;
}
