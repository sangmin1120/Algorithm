/**
 * 부분수열의 합: 수열을 더한 값이 S가 되는 경우의 수
 * BT (s2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,s; // input - n개의 수, 목표 합 s
int arr[21]; // n의 배열
int ans; // s가 되는 경우의 수
int visited[21];

void bt(int idx, int sum) {

    // exit conditional
    if (idx == n) {
        if (sum == s)  ans++;
        return;
    }

    // logic
    bt(idx+1, sum+arr[idx]);
    bt(idx+1, sum);
}
void solution() {

    bt(0,0);

    if (s==0)   ans--; // s==0 일때, 공집합 제외
    cout << ans << endl;
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input
    cin >> n >> s;
    for (int i=0;i<n;i++)   cin >> arr[i];

    solution();

    return 0;
}