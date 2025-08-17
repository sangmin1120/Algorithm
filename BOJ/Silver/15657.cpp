/**
 * N과 M (8) - N개의 자연수 중 M개, 중복 가능, 오름 차순
 * BACKTRAKING  (S3)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
vector<int> res;

void bt(int count, int prev) {
    // end cond
    if (count==m) {
        for (auto r : res) {
            cout << r << ' ';
        }
        cout << '\n';
        return;
    }

    // logic
    for (int i=prev;i<n;i++) {
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