/*************************************************************************
	> File Name: OJ245货仓选址.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 03 Jan 2021 11:03:18 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000 
int a[MAX_N + 5], ind[MAX_N + 5]; 

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	nth_element(a + 1, a + (n + 1) / 2, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= 100; i++) ind[i] = rand() % 10000;
	nth_element(ind + 1, ind + (100 + 1) / 2, ind + 1 + 100);
	for (int i = 1; i <= 100; i++) {
		cout << ind[i] << " ";
	}
	cout << endl;
	//sort(a + 1, a + 1 + n);
	int p = a[(n + 1) >> 1], ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += abs(a[i] - p);
	}
	cout << ans << endl;
	return 0;
}
