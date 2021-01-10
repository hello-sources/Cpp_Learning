/*************************************************************************
	> File Name: Main.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 10 Jan 2021 02:28:39 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include "BSTree.h" 
#include <set>
using namespace std;

class A {
public :
	void operator++() {
		cout << "No param" << endl;
	}
	void operator++(int) {
		cout << "has int param" << endl;
	}
};

int main() {
	haizei::BSTree<int> root_bs;
	std::set<int> root_s;
	for (int i = 0; i < 10; i++) {
		root_bs.insert(rand() % 100);
		root_s.insert(rand() % 100);
	}
	for (std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) {
		cout << *iter << endl;
	}
	for (haizei::BSTree<int>::iterator iter = root_bs.begin(); iter != root_bs.end(); iter++) {
		cout << *iter << endl;
	}
	return 0;
}
