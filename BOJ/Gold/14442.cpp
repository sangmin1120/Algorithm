/**
 * 벽 부수고 이동하기2: k개의 벽 부수고 이동
 * bfs (g3)
 */
#include <bits/stdc++.h>
using namespace std;

#define NUM_MAX 1000
#define K_MAX 10

int r,c,k;
int board[NUM_MAX][NUM_MAX];
int dist[NUM_MAX][NUM_MAX][K_MAX];
int direct[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

bool InRange(int x,int y) {
    return x>=0 && x<r && y>=0 && y<c;
}
void bfs() {
    queue<tuple<int,int,int>> q;
    q.push({0,0,0}); // x,y, 벽 부순 개수
    dist[0][0][0] = 1;

    while(!q.empty()) {
        int x,y,cnt;
        tie(x,y,cnt) = q.front();   q.pop();

        // 종료 조건
        if (x==r-1 && y==c-1) {
            cout << dist[x][y][cnt] << '\n';
            return;
        }

        //탐색
        for (int i=0;i<4;i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            int nextdist = dist[x][y][cnt] + 1;

            if (!InRange(nx,ny))    continue;

            //그냥 이동
            if (board[nx][ny]==0 && dist[nx][ny][cnt]==-1) {
                q.push({nx,ny,cnt});
                dist[nx][ny][cnt] = nextdist;
            }

            // 벽 부수고 이동
            if (board[nx][ny]==1 && cnt<k && dist[nx][ny][cnt+1]==-1) {
                q.push({nx,ny,cnt+1});
                dist[nx][ny][cnt+1] = nextdist;
            }
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
            board[i][j] = s[j]-'0';
            for (int w=0;w<=k;w++)
                dist[i][j][w] = -1; // k까지 포함하는 초기화 주의
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