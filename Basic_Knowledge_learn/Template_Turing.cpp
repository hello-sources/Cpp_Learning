/*************************************************************************
	> File Name: Template_Turing.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 10:45:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//模板检查是否是素数 
template<int x>
struct IsOdd {
	constexpr static int r = x % 2;
};

template<int i, int x>
struct getNextK {
	constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};

template<int i, int x, int k>
struct Test {
	constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
}; 

template<int i, int x>
struct Test<i, x, 0> {
	constexpr static int r = 1;
}; 

template<int i, int x>
struct Test<i, x, 1> {
	constexpr static int r = 0;
}; 

template<int x>
struct is_prime {
	constexpr static int r = Test<2, x, 2>::r;
};

//一般情况下检查是否是素数 
//bool __is_prime(int i, int x) {
//	if (i * i > x) return true; //k = 0
//	if (x % i == 0) return false; //k = 1
//	return __is_prime(i + 1, x); //k = 2
//}
//
//bool is_prime_1(int x) {
//	return __is_prime(2, x);
//}

int main() {
	cout << IsOdd<5>::r << endl;
	cout << IsOdd<6>::r << endl;
	cout << is_prime<9973>::r << endl;
	cout << is_prime<10000>::r << endl;
	return 0;
}
