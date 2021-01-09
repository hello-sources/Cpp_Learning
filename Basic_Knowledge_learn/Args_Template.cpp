/*************************************************************************
	> File Name: Args_Template.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 09 Jan 2021 09:31:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>//终止条件放上面 
void print(const T &a) {
	cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
	cout << a << " ";
	print(args...);
	return ;
} 

template<int n, typename T, typename ...ARGS> 
struct ARG {
	typedef typename ARG<n - 1, ARGS...>::getT getT;
	typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
	typedef T getT;
}; 

template<typename T>
struct ARG<0, T> {
	typedef T getT;
	typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public : 
	T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
		return a + b;
	}

};

int main() {
	print(123, 23.5);
	print(123, 23.5,  "hello world", 'o');
//	cout << sizeof(ARG<int, double, float>::getT) << endl;
//	cout << sizeof(ARG<int, double, float>::rest::getT) << endl;
//	cout << sizeof(ARG<int, double, float>::rest::rest::getT) << endl;

//	ARG<int, double, float>::getT a = 123;
//	ARG<int, double, float>::rest::getT b = 12.3;
//	ARG<int, double,float>::rest::rest::getT c = 123.45;
//	cout << a << " " << b << " " << c << endl;
	Test<int(double, float)> d;
//	Test<int(double, float, int, int, int)> e;
	cout << d(2.3, 4.5) << endl;	
	return 0;
}
