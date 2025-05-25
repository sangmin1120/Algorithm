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
int bfs() {

    int dist[r][c][2];
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    dist[0][0][0] = dist[0][0][1] = 1;


    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while (!q.empty()) {
        int cx,cy,broken;
        tie(cx,cy,broken) = q.front(); q.pop();

        if (cx==r-1 && cy==c-1) return dist[cx][cy][broken];
        int nextdist = dist[cx][cy][broken] + 1;

        for (int d=0;d<4;d++) {
            int nx = cx + direct[d][0];
            int ny = cy + direct[d][1];

            if (!InRange(nx,ny))    continue;

            if (boards[nx][ny]==0 && dist[nx][ny][broken]==-1) {
                dist[nx][ny][broken] = nextdist;
                q.push({nx,ny,broken});
            }

            // 벽은 부술 때
            if (!broken && boards[nx][ny]==1 && dist[nx][ny][broken]==-1) {
                dist[nx][ny][1] = nextdist;
                q.push({nx,ny,1});
            }
        }
    }
    return -1;
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

    //solution
    int ans = bfs();

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}