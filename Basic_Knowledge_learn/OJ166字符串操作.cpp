/*************************************************************************
	> File Name: OJ166字符串操作.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 04 Jan 2021 11:16:14 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	int n;
	cin >> str1 >> n >> str2;
//	str.insert(3, "hello world");
//	cout << str << endl;
//	cout << str.find('x') << endl; 
//	cout << str.rfind('x') << endl;	
	cout << min(str1.length(), (size_t)100) << endl;
	str1.insert(n - 1, str2);
	cout << str1 << endl;
	cout << str1.length() - str1.rfind('x') << endl;
	return 0;
} 
