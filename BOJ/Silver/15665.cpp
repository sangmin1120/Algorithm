/**
 * N과 M (11) - 중복 수열 X, 여러 가지 방문
 * BACKTRAKING (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
vector<int> res;
int checked[10];

void bt(int count) {
    // exit cond
    if (count==m) {
        for (auto r : res)  cout << r << ' ';
        cout << '\n';
        return;
    }

    // logic
    for (int i=0;i<n;i++) {
        res.push_back(v[i]);
        bt(count+1);
        res.pop_back();
    }
}
void solution() {

    sort(v.begin(),v.end());

    bt(0);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int n2 = 0;
    for (int i=0;i<n;i++) {
        int temp;   cin >> temp;
        if (!checked[temp]) {
            v.push_back(temp);
            checked[temp] = 1;
            n2++;
        }
    }
    n = n2;
    solution();

    return 0;
}