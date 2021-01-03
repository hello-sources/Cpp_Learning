/*************************************************************************
	> File Name: hash_table模板.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:12:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include "hash_table模板.h"
using namespace std;

struct A {
    A(int x, int y) : x(x), y(y) {}
    int x, y;
    bool operator==(A const &a) const {
        return this->x == a.x && this->y == a.y;
    }
};

struct myhash {
    int operator()(A const &a) const {
        return a.x + a.y;
    }
};

int main() {
    A a(0, 9), b(10, 12);
    unordered_map<A, int, myhash> arr;
    arr[a] = 1;
    arr[b] = 2;
    cout << arr[a] << endl;
    cout << arr[b] << endl;
    haizei::unordered_map<int, int> arr2;
    arr2[129883] = 65;
    arr2[623] = 23;
    cout << arr2[129883] << endl;
    cout << arr2[623] << endl;

    haizei::unordered_map<A, int, myhash> arr3;
    arr3[a] = 1;
    arr3[b] = 2;
    cout << arr3[a] << endl;
    cout << arr3[b] << endl;
    return 0;
}
