/**
 * N과 M (4) - 1~N까지 자연수 중에서 M개를 고른 수열, 중복 허용, 오름차순으로 출력
 * BACKTRACKING (S3)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> res;

void bt(int count,int prev) {
    //exit cond
    if (count==m) {
        for (auto r : res)  cout << r << ' ';
        cout << '\n';
        return;
    }

    //logic
    for (int i=prev;i<=n;i++) {
        res.push_back(i);
        bt(count+1,i);
        res.pop_back();
    }
}
void solution() {

    bt(0,1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    cin >> n >> m;

    solution();

    return 0;
}