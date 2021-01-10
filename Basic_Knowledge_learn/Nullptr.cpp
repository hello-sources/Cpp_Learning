/*************************************************************************
	> File Name: Nullptr.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 03:43:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void f(int x) {
	cout << x << endl;
	return ;
}

void f(int *p) {
	cout << p << endl;
}

int main() {
	int n = 123;
	f(n);
	f(&n);
	f(nullptr); 
	return 0;
} 
