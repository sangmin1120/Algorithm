/**
 * 소문난 칠공주 - 가로, 세로 인접할 때, 적어도 S파 4개가 될 수 있는 경우의 수
 * BACKTRACKING + DFS
 */
#include <bits/stdc++.h>
using namespace std;

int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // 동,서,남,북

char boards[5][5];
int n = 5; // 5 X 5
int res = 0;

bool InRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}
bool checkAdj(vector<int> &picked) {
    queue<pair<int,int>> q;
    bool vis[n][n] = {};
    bool sel[n][n] = {};

    for (auto idx : picked) sel[idx/n][idx%n] = true;

    q.push({picked[0]/n,picked[0]%n});
    vis[picked[0]/5][picked[0]%5] = true;
    int cnt = 1;

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();

        for (int d=0;d<4;d++) {
            int nx = x+direct[d][0];
            int ny = y+direct[d][1];
            if (InRange(nx,ny) && sel[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
    return cnt == 7;
}
void solution() {

    vector<int> v(25,0);
    fill(v.end()-7,v.end(),1); // bit mask -> 7명

    do {

        vector<int> picked;
        int s_cnt = 0;
        for (int i=0;i<n*n;i++) {
            if (v[i]) { // 앉아있음
                picked.push_back(i);
                if (boards[i/n][i%n]=='S')  s_cnt++;
            }
        }
        if (s_cnt>=4 && checkAdj(picked))   res++;
    } while(next_permutation(v.begin(),v.end())); // 비트 마스크 순열로 인접과 조건을 판단

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    for (int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for (int j=0;j<n;j++) {
            boards[i][j] = temp[j];
        }
    }

    solution();

    return 0;
}
