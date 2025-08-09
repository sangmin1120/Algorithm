/**
 * N과 M (7) - N개의 자연수 중 M개를 선택, 같은 수를 여러 번 골라도 된다.
 * BACKTRAKING (S3)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
vector<int> res;
void bt(int count) {
    // exit cond
    if (count==m) {
        for (auto r : res)
            cout << r << ' ';
        cout << '\n';
        return;
    }

    // logic
    for (int val : v) {
        res.push_back(val);
        bt(count+1);
        res.pop_back();
    }
}
void solution() {

    // sort
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