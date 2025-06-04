/**
 * N과 M(1): 1~N 사이 자연수 중에서 중복 없이 M개를 고른 수열
 * BT (s3)
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10]; // 숫자 사용 여부

void bt(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (isUsed[i]) continue;

        isUsed[i] = true;
        arr[cnt] = i;
        bt(cnt + 1);
        isUsed[i] = false;
    }
}

void solution() {
    cin >> n >> m;
    bt(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
    return 0;
}
