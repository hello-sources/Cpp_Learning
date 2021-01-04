/*************************************************************************
	> File Name: map.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 04 Jan 2021 12:43:55 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
	string name;
	int n, age;
	set<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(2);
	s.insert(3);
	cout << *s.begin() << endl;
	s.erase(s.begin());
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	} 
	cout << endl;
	map<int, string> arr; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		arr[age] = name;
	}
	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		cout << iter->second << endl;
	}
	return 0;
}
