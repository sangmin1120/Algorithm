/**
 * N과 M (2) - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 오름차순으로 출력
 * BACKTRACKING (S3)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
int visited[10];

void bt(int count, int prev) {
    // exit cond
    if (count==m) {
        for (int i=1;i<=n;i++)
            if (visited[i]) cout << i << ' ';
        cout << '\n';
        return;
    }

    // logic
    for (int i=prev+1;i<=n;i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        bt(count+1,i);
        visited[i] = 0;
    }
}
void solution() {

    bt(0,0);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    cin >> n >> m;

    solution();

    return 0;
}