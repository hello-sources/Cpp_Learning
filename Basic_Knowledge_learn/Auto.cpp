/*************************************************************************
	> File Name: Auto.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 03:32:33 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

string randstring(int n) {
	string ret = "";
	for (int i = 0; i < n; i++) {
		char ch = rand() % 26 + 'A';
		ret += ch;
	}
	return ret;
}

int my_seed = 1;
void my_srand(int seed) {
	my_seed = seed;
} 

int my_rand() {
	my_seed = my_seed * 3 % 101;
	return my_seed;
}

int main() {
	my_srand(time(0));
	for (int i = 0; i < 10; i++) {
		cout << my_rand() << endl;
	}
	long long a[100] = {0};
	auto b = a;
	cout << sizeof(b) << endl;
	map<string, int> arr;
	arr["hello world"] = 123;
	arr["haizei"] = 456;
	arr["harbin"] = 987;
	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	srand(time(0));
	map<string, int> ind;
	for  (int i = 0; i < 10; i++) {
		ind[randstring(rand() % 10 + 3)] = rand();
	}
	for (auto iter = ind.begin(); iter != ind.end(); iter++) {
		cout << iter->first << " " << iter->second << endl; 
	} 
	for (auto x : ind) { //根据PHP语法的来的 
		cout << x.first << " " << x.second << endl;
	}
	return 0;
} 
