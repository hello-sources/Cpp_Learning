/*************************************************************************
	> File Name: virtual_table.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 04 Nov 2020 10:25:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    virtual void run(int x) {
        cout << "class A run" << endl;
    }
};

class B : public A {
public :
    void run(int x) {
        cout << "class B run" << endl;
        cout << this << endl;
        cout << x << endl;
    }
};

typedef void (*func)(void *, int);

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    B b;
    ((func **)(&b))[0][0](&b, 123);

    return 0;
}
