/**
 * 벽 부수고 이동하기: 벽 1개만 부술 때, 최단 거리
 * BFS (g3)
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r;
int c;
int boards[1001][1001];
int visited[1001][1001];
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<int,int>> walls;

int ans = INT_MAX;

bool InRange(int x,int y) {
    return x>=0&&x<r&&y>=0&&y<c;
}
void bfs() {

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int d=0;d<4;d++) {
            int nx = cur.X + direct[d][0];
            int ny = cur.Y + direct[d][1];

            if (nx==r-1&&ny==c-1) {
                ans = min(ans,visited[cur.X][cur.Y]+1);
            }
            if (!InRange(nx,ny) || visited[nx][ny] || boards[nx][ny]==1)    continue;

            q.push({nx,ny});
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
        }
    }

    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}
void solution() {
    // init
    cin >> r >> c;
    for (int i=0;i<r;i++) {
        string s;
        cin >> s;
        for (int j=0;j<c;j++) {
            boards[i][j] = s[j] - '0';
            if (boards[i][j]==1)
                walls.push_back({i,j});
        }
    }

    for (auto w : walls) {
        boards[w.X][w.Y] = 0; // 벽 부수기
        fill(&visited[0][0],&visited[1001][0],0);
        bfs();
        boards[w.X][w.Y] = 1; // 복구
    }
    
    //출력
    cout << (ans==INT_MAX)?-1:ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}