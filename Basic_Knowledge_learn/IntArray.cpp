/*************************************************************************
	> File Name: IntArray.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 08 Jan 2021 04:07:35 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class IntArray {
public :
	IntArray(int n) : n(n) {
		this->arr = new int[n];
	}
	IntArray(const IntArray &obj) : n(obj.n){
		this->arr = new int[n];
		for (int i = 0; i < n; i++) {
			this->arr[i] = obj.arr[i];
		}
	}
	int &operator[](int ind) {
		if (ind >= 0) {
			return this->arr[ind];
		}
		return this->arr[n + ind];
	}
	void operator+=(int x) {
		for  (int i = 0; i < n; i++) {
			this->arr[i] += x;
		}
		return ;
	}
	IntArray operator++() {//前++ 
		for (int i = 0; i < n; i++) {
			this->arr[i] += 1;
		}
		return *this;
	}
	IntArray operator++(int x) {//后++ 
		IntArray ret = (*this);
		for (int i = 0; i < n; i++) {
			this->arr[i] += 1;
 		}
		return ret;
	}
	~IntArray() {
		delete[] this->arr;
	}
	friend ostream &operator<<(ostream &, const IntArray &);
private :
	int *arr, n;
};

ostream &operator<<(ostream &out, const IntArray &a) {
	out << "<class IntArray> : ";
	for (int i = 0; i < a.n; i++) {
		out << a.arr[i] << " ";
	}
	return out;
}

int main() {
	srand(time(0));
	IntArray a(10);
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;
	} 
	cout << a[4] << endl;
	cout << a[-2] << endl; //输出倒数第二位的值
	cout << a << endl; //输出整个数组中的元素 
	a += 5; //给数组中所有元素加5
	cout << a << endl; //输出数组中所有元素
	cout << (a++) << endl; //给数组所有元素都加一
	cout << (++a) << endl; //给数组所有元素都加一 
	return 0;
}
