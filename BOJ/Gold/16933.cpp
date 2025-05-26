/**
 * 벽 부수고 이동하기3: 낮에만 벽을 부술 수 있음, 가만히 있는 것도 결과에 +1
 * bfs (g1)
 */
#include <bits/stdc++.h>
using namespace std;

#define NUM_MAX 1000
#define K_MAX 10

#define DAY 0
#define NIGHT 1

int r,c,k;
int board[NUM_MAX][NUM_MAX];
int dist[NUM_MAX][NUM_MAX][K_MAX][2];

int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool InRange(int x,int y) {
    return x>=0 && x<r && y>=0 && y<c;
}
void bfs() {
    queue<pair<pair<int,int>,pair<int,int>>> q; //(x,y),(부순 벽의 수, 낮or밤)
    q.push({{0,0},{0,DAY}});
    dist[0][0][0][DAY] = 1;

    while (!q.empty()) {
        auto cur = q.front();   q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int cnt = cur.second.first; // 벽 부순 개수
        int time = (cur.second.second); // 낮/밤

        // 종료조건
        if (x==r-1 && y==c-1) {
            cout << dist[x][y][cnt][time] << '\n';
            return;
        }

        //탐색
        for (int d=0;d<4;d++) {
            int nx = x + direct[d][0];
            int ny = y + direct[d][1];
            int nextdist = dist[x][y][cnt][time] + 1;

            if (!InRange(nx,ny))    continue;
            
            // 빈곳이면 그냥 가면 된다.
            if (board[nx][ny]==0 && dist[nx][ny][cnt][!time]==-1) {
                dist[nx][ny][cnt][!time] = nextdist;
                q.push({{nx,ny},{cnt,!time}});
            }

            // 비어있지 않다면
            else {
                // 벽을 깰 수 없다.
                if (cnt==k) continue;

                // 낮이라면 벽을 깨고 가
                if (time==DAY) {
                    if (dist[nx][ny][cnt+1][!time] > 0) continue;
                    dist[nx][ny][cnt+1][!time] = nextdist;
                    q.push({{nx,ny},{cnt+1,!time}});
                }
                // 밤이라면 낮까지 대기
                else {
                    if (dist[x][y][cnt][!time] > 0)   continue;
                    dist[x][y][cnt][!time] = nextdist;
                    q.push({{x,y},{cnt,!time}});
                }
            }
        }

        // 가만히 있기
        if (time==NIGHT && dist[x][y][cnt][!time]==-1) {
            q.push({{x,y},{cnt,!time}});
            dist[x][y][cnt][!time] = dist[x][y][cnt][time] + 1;
        }
    }
    cout << -1 << '\n';
}
void solution() {
    //init
    cin >> r >> c >> k;
    for (int i=0;i<r;i++) {
        string s;
        cin >> s;
        for (int j=0;j<c;j++) {
            board[i][j] = s[j] - '0';
            for (int b=0;b<=k;b++){
                dist[i][j][b][0] = -1;
                dist[i][j][b][1] = -1;
            }
        }
    }

    bfs();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}