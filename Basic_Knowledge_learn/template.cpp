/*************************************************************************
	> File Name: template.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 11 Nov 2020 11:07:26 PM CST
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

class A {
public :
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private:
    int x;
};

template<typename T, typename U>
auto add(T &a, U &b) -> decltype(a + b) {
    return a + b;
}

template<typename T>
struct Print {
    template<typename U>
    void operator()(U &&a) {
        cout << a << endl;
    }
};

template<typename T>
void print(const T &a) {
    cout << a << endl;
    cout << "end----" << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS... args) {
    cout << a << endl;
    print(args...);
    return ;
}

template<int n, typename T, typename ...U>
struct ARG {
    typedef T type;
    typedef typename ARG<n - 1, U...>::getT getT;
};

template<typename T, typename ...U>
struct ARG<1, T, U...> {
    typedef T type;
    typedef T getT;
};

template<typename T, typename ...U> struct Convertor;
template<typename T, typename ...U>
struct Convertor<T(U...)> {
    T operator()(
        const typename ARG<1, U...>::getT &a, 
        const typename ARG<2, U...>::getT &b) {
        return a + b;
    }
};

template<int n, int m>
void func() {
    cout << "func : " << n + m << endl;
    return ;
}

template<int n>
struct IsOdd {
    constexpr static int r = n % 2;
};

template<int n, int i>
struct GetNextN {
    const static int r = (n > 0 && n % i != 0) * n;
};

template<int n, int i>
struct GetNextM {
    const static int r = (i * i <= n ? i + 1 : 0);
};

template<int n, int i>
struct TestPrime {
    const static int r = TestPrime<GetNextN<n, i>::r, GetNextM<n, i>::r>::r;
};

template<int i>
struct TestPrime<0, i> {
    const static int r = 0;
};

template<int n>
struct TestPrime<n, 0> {
    const static int r = 1;
};

template<int n>
struct IsPrime {
    const static int r = TestPrime<n, 2>::r;
};

int main() {
    int a = 3, b = 4;
    double c = 4.5;
    A d(2);
    Print<int> plog;
    plog(a);
    plog(c);
    func<2, 3>();
    func<3, 4>();
    func<7, 9>();
    func<3, 9>();
    plog(add(a, b));
    cout << add(a, c) << endl;
    cout << add(c, a) << endl;
    cout << add(d, a) << endl;
    print(1, 2.3, "hello world");
    
    Convertor<int(double, double)> conv;
    cout << conv(3.4, 4.5) << endl;

    cout << IsOdd<2>::r << endl;
    cout << IsOdd<3>::r << endl;

    cout << IsPrime<9>::r << endl;
    cout << IsPrime<1000007>::r << endl;
    return 0;
}
