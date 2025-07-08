/**
 * N-Queen: N x N 체스판 위에 퀸 N개를 서로 공격할 못하는 경우의 수
 * BT (G4) - col[row]로 저장
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int col[16];
int ans; // 총 경우의 수

bool check(int r) {

    for (int l=0;l<r;l++) {
        if (col[r]==col[l] || abs(col[r]-col[l]) == r-l)
            return false;
    }
    return true;
}
void bt(int idx) {

    // exit condition
    if (idx==n) {
        ans++;
    }

    // logic
    for (int i=0;i<n;i++) {

        col[idx]=i;
        if (check(idx)) {
            bt(idx+1);
        }
    }
}
void solution() {

    bt(0);

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;

    solution();

    return 0;
}