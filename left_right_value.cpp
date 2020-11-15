/*************************************************************************
	> File Name: left_right_value.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:14:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define P(func, x) { \
    cout << #func << "(" << #x << ") "; \
    func(x); \
}


void Judge2(int &x) {
    cout << "left value" << endl;
    return ;
}

void Judge2(int &&x) {
    cout << "right value" << endl;
    return ;
}

void Judge(int &x) {
    cout << "left value" << endl;
    P(Judge2, forward<int &>(x));
    return ;
}

void Judge(int &&x) {
    cout << "right value" << endl;
    P(Judge2, forward<int &&>(x));
    return ;
}

int main() {
    int a = 1, b = 2;
    P(Judge, a);
    P(Judge, b);
    P(Judge, 123);
    P(Judge, a + b);
    P(Judge, a++);
    P(Judge, ++a);
    return 0;
}
