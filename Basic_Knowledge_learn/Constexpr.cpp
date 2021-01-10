/*************************************************************************
	> File Name: Constexpr.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 03:52:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

constexpr int f(int i) {
	return 2 * i;
}

struct A {
	constexpr A(int x, int y) : x(x), y(y) {}
	int x, y;
}; 

int main() {
	int n;
	cin >> n;
	const int a = n + 3;
	constexpr int b = f(123) + 567;
	cout << f(n) << endl;
	constexpr A c(2, 3);
	A d(n, 4);
	return 0;
} 
