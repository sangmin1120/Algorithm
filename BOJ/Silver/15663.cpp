/**
 * N과 M(9) - n 개의 자연수 중에서 m 개 선택, 중복되는 수열 없이 출력
 * BACKTRACKING (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;

void solution() {

    sort(v.begin(),v.end());

    
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
