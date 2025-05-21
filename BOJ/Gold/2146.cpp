/**
 * 다리 만들기: 섬을 잇는 최소 거리 구하기
 * BFS
 */
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_N 101
#define X first
#define Y second

//탐색 상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n; // board 크기
int board[MAX_N][MAX_N];

vector<pair<int,int>> land[10001]; // 섬의 좌표
int visit[101][101];

bool InRange(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<n);
}
void is_island() {

    int island_number = 1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            
            if (visit[i][j] || board[i][j]==0) continue; // 방문 || 바다 -> pass
            queue<pair<int,int>> Q;
            Q.push({i,j});
            visit[i][j] = true;

            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = island_number;
                land[island_number].push_back({cur.X,cur.Y});

                for (int d=0;d<4;d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];

                    if (!InRange(nx,ny) || visit[nx][ny] || board[nx][ny]==0) continue; // 범위 밖 || 바다
                    Q.push({nx,ny});
                    visit[nx][ny] = true;
                }
            }
            island_number++;
        }
    }
}
int min_dist(int idx) {
    queue<tuple<int,int,int>> Q;
    for (auto e : land[idx]) {
        Q.push({e.X, e.Y, 0});
        visit[e.X][e.Y] = idx;
    }
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int cx,cy,t;
        tie(cx,cy,t) = cur;

        for (int d=0;d<4;d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (!InRange(nx,ny) || visit[nx][ny]==idx) continue; // 범위 밖 || 이전에 방문
            if (board[nx][ny]==idx) continue; // 같은 섬일 경우
            if (board[nx][ny]!=0)
                return t; // 다른 섬
            
            Q.push({nx,ny,t+1});
            visit[nx][ny] = idx;
        }
    }
    return 9999;
}
void solution() {

    // 각 이어진 섬을 BFS로 확인
    is_island();

    // (i,j)에서 다른 섬까지의 최소 거리를 BFS로 구하기
    int ans = INT_MAX;
    for (int i=1;i<10000;i++) {
        if (land[i].empty()) break;
        ans = min(ans,min_dist(i));
    }

    cout << ans;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    //init
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> board[i][j];
        
    solution();
    return 0;
}