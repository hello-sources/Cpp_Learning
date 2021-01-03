/*************************************************************************
	> File Name: OJ270.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 31 Oct 2020 09:24:24 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head, tail;

//C语言实现单调队列
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    int ans = arr[0];
    for (int i = 1; i <= n; i++) {
        if (arr[i]  - arr[q[head]] > ans) ans = arr[i] - arr[q[head]];
        while (tail - head && arr[q[tail - 1]] > arr[i]) tail--;
        q[tail++] = i;
        if (i - q[head] >= m) head++;
    }
    cout << ans << endl;
    return 0;
} 
