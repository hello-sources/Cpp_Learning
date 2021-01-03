/*************************************************************************
	> File Name: return_value.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 03 Nov 2020 10:06:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    public : 
        A() {
            cout << this << " constructor" << endl;
        }
        A(const A &obj) {
            cout << this << " copy constructor" << endl;
        }
        A &operator=(const A &obj) {
            cout << this << " operator = " << endl;
            return *this;
        }
        ~A() {
            cout << this << " deconstructor" << endl;
        }
};

A func() {
    A temp;
    cout << &temp << endl;
    return temp;
}

int main() {
    //func();
    //A a;
    //a = func();
    A a = func();
    cout << &a << endl;
    return 0;
}
