/**
 * N과 M (10) - 중복되는 순열 없이
 * BACKTRAKING (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
vector<int> res;
int visited[10];

void bt(int count, int prev_idx) {
    // exit cond
    if (count==m) {
        for (auto r : res)    cout << r << ' ';
        cout << '\n';
        return;
    }

    int prev = 0;
    // logic
    for (int i=prev_idx+1;i<n;i++) {

        if (!visited[i] && prev!=v[i]) {
            visited[i] = 1;
            res.push_back(v[i]);
            prev = v[i];
            bt(count+1,i);
            visited[i] = 0;
            res.pop_back();
        }
    }
}
void solution() {

    sort(v.begin(),v.end());

    bt(0,-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    solution();

    return 0;
}