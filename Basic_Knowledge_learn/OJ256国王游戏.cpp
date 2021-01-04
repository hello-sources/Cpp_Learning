/*************************************************************************
	> File Name: OJ256国王游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 04 Jan 2021 04:00:06 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Data {
	int a, b;
	bool operator<(const Data &obj) const {
		return a * b < obj.a * obj.b;
	}
};
vector<Data> arr;

int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin() + 1, arr.end());
	int p = arr[0].a, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (p / arr[i].b > ans)  ans = p / arr[i].b;
		p *= arr[i].a;
	}
	cout << ans << endl;
	return 0;
}
