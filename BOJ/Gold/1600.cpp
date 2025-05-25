/**
 * 말이 되고픈 원숭이: k번 체스의 나이트 처럼 움직임, 나머지는 동서남북 -> (0,0)->(n,n) 최소
 * bfs (g3)
 */
#include <bits/stdc++.h>
using namespace std;

int r,c;
int k;
int board[201][201];
int dist[201][201][31];

int chess[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool InRange(int x,int y) {
    return x>=0 && x<r && y>=0 && y<c;
}
void bfs() {
    deque<tuple<int,int,int>> dq;
    dq.push_back({0,0,0}); // 0,0 까지 가는데 chess 방식을 사용한 횟수
    dist[0][0][0] = 0;

    while (!dq.empty()) {
        int x,y,temp;
        tie(x,y,temp) = dq.front(); dq.pop_front();

        // 종료 조건
        if (x==r-1 && y==c-1) {
            cout << dist[x][y][temp] << '\n';
            return;
        }

        // 나이트 처럼 움직일 때
        if (temp < k) {
            for (int d=0;d<8;d++) {
                int nx = x + chess[d][0];
                int ny = y + chess[d][1];

                if (!InRange(nx,ny) || board[nx][ny]==1)    continue;
                // 최소 보장
                if (dist[nx][ny][temp+1]==-1 || dist[nx][ny][temp+1] > dist[x][y][temp]+1) {
                    dq.push_back({nx,ny,temp+1});
                    dist[nx][ny][temp+1] = dist[x][y][temp] + 1;
                } 
            }
        }

        // 일반 동서남북
        for (int d=0;d<4;d++) {
            int nx = x + direct[d][0];
            int ny = y + direct[d][1];

            if (!InRange(nx,ny) || board[nx][ny]==1)    continue;

            if (dist[nx][ny][temp]==-1 || dist[nx][ny][temp] > dist[x][y][temp] + 1) {
                dq.push_back({nx,ny,temp});
                dist[nx][ny][temp] = dist[x][y][temp] + 1;
            }
        }
    }

    // 도착 실패
    cout << -1 << '\n';
    return;
}
void solution() {
    //init
    cin >> k;
    cin >> c >> r;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++) {
            cin >> board[i][j];
            for (int b=0;b<=k;b++)
                dist[i][j][b] = -1;
        }
    
    
    bfs();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}