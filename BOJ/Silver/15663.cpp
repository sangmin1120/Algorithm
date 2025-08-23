/**
 * N과 M(9) - n 개의 자연수 중에서 m 개 선택, 중복되는 수열 없이 출력
 * BACKTRACKING (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int visited[10];
vector<int> res;

void bt(int count) {
    // exit cond
    if (count==m) {
        for (auto r : res)
            cout << r << ' ';
        cout << '\n';
        return;
    }

    //logic
    int temp=0;
    for (int i=0;i<n;i++) {
        if (!visited[i] && temp!=v[i]) {
            visited[i] = 1;
            res.push_back(v[i]);
            temp = v[i];
            bt(count+1);
            visited[i] = 0;
            res.pop_back();
        }
    }
}
void solution() {

    sort(v.begin(),v.end());

    bt(0);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    solution();

    return 0;
}
