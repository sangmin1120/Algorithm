/**
 * N과 M (6) - N개의 자연수 중에서 M개를 고른 수열, 오름차순, 중복되는 수열을 출력하면 안된다. ex) (1,7) == (7,1)
 * BACKTRACKING (s3)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int visited[10];
int res[10];

void bt(int count, int prev_idx) {
    //exit cond
    if (count==m) {
        for (int i=0;i<m;i++)   cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    //logic
    for (int i=prev_idx+1;i<n;i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        res[count] = arr[i];
        bt(count+1,i);
        visited[i] = 0;
    }
}
void solution() {
    sort(arr,arr+n);

    bt(0,-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    cin >> n >> m;
    for (int i=0;i<n;i++)   cin >> arr[i];

    solution();

    return 0;
}