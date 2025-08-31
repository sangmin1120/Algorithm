/**
 * N과 M (12)
 * BACKTRAKING (S2)
 */
#include <bits/stdc++.h> 
using namespace std;

int n,m;
vector<int> v;
vector<int> res;
int isUsed[10001];

void bt(int count, int pre_idx) {
    // exit cond
    if (count==m) {
        for (auto r : res)  cout << r << ' ';
        cout << '\n';
        return;
    }

    // logic
    for (int i=pre_idx;i<n;i++) {
        res.push_back(v[i]);
        bt(count+1,i);
        res.pop_back();
    }
}
void solution() {

    sort(v.begin(),v.end());

    bt(0,0);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int cnt=0;
    for (int i=0;i<n;i++) {
        int temp;   cin >> temp;
        // 중복을 없애기
        if (!isUsed[temp]) {
            v.push_back(temp);
            isUsed[temp] = 1;
            cnt++;
        }
    }

    n = cnt;
    solution();

    return 0;
}