/**
 * N과 M(12)
 * BACKTRAKING (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
vector<int> res;

void solution() {

    sort(v.begin(),v.end());

    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++) {
        int temp;   cin >> temp;
        v.push_back(temp);
    }

    solution();

    return 0;
}