/*************************************************************************
	> File Name: OJ270.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 31 Oct 2020 09:24:24 PM CST
 ************************************************************************/

#include <iostream>
#include <deque>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
deque<int> q;

//C++中的双端队列
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    q.push_back(0);
    int ans = arr[0];
    for (int i = 1; i <= n; i++) {
        if (arr[i]  - arr[q.front()] > ans) ans = arr[i] - arr[q.front()];
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() >= m) q.pop_front();
    }
    cout << ans << endl;
    return 0;
} 
