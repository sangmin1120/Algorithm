/**
 * 암호 만들기 - 최소 모음 1개, 최소 자음 2개의 조건
 * BACKTRACKING - (G5)
 */
#include <bits/stdc++.h>
using namespace std;

int l,c; // 조건의 길이, 사용할 수 있는 알파벳의 수
vector<char> v;
vector<char> res;

bool check_cond() {
    int con=0; // 자음
    int vow=0; // 모음

    for (auto r : res) {
        if (r=='a' || r=='i' || r=='o' || r=='u' || r=='e')
            vow++;
        else
            con++;
    }
    if (vow>=1 && con>=2)   return true;

    return false;
}
void bt(int count, int prev_idx) {

    // exit cond
    if (count == l) {
        if (check_cond()) {
            for (auto r : res)  cout << r;
            cout << '\n';
        }
        return;
    }

    // logic
    for (int i=prev_idx+1;i<c;i++) {
        res.push_back(v[i]);
        bt(count+1, i);
        res.pop_back();
    }
}
void solution() {

    sort(v.begin(),v.end());
    bt(0,-1);

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    cin >> l >> c;
    for (int i=0;i<c;i++) {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    solution();
    return 0;
}