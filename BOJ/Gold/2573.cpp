/**
 * 빙산: 빙산이 두 덩어리가 될 때, 최소 시간
 * BFS (g4)
 */
#include <bits/stdc++.h>
using namespace std;

int r,c;
int board[301][301];
int vis[301][301];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void initvis() {
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            vis[i][j] = 0;
}
bool InRange(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c;
}
void melting() {
    // 주변의 0 숫자 세기
    int zero[301][301] = {0};
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            for (int d=0;d<4;d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (InRange(nx,ny) && board[nx][ny]==0) zero[i][j]++;
            }
        }
    }

    // 빙산 지우기
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            board[i][j] = max(0, board[i][j]-zero[i][j]);
        }
    }
}
int status() {
    int cnt1=0;
    int x,y;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (board[i][j]>0) {
                cnt1++;
                x = i;
                y = j;
            }
        }
    }

    if (cnt1==0)    return 0;

    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    int cnt2=0; // x,y 와 붙어있는 빙산의 수
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt2++;
        for (int d=0;d<4;d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if (!InRange(nx,ny) || vis[nx][ny]==1 || board[nx][ny]==0)  continue;

            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }

    if (cnt1==cnt2) return 1; // 아직 한 덩이
    return 2;
}
void solution() {
    // init
    cin >> r >> c;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            cin >> board[i][j];
    
    int year=0;
    while(1) {
        year++;
        initvis();
        melting();
        int check = status();
        if (check==0) {
            cout << 0;
            return;
        }
        else if (check==1)   continue; // 아직 한 덩이
        else 
            break;
    }
    cout << year << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}