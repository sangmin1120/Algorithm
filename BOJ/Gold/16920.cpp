/**
 * 확장 게임: 성에서 확장 했을 때, 각각의 점수
 * bfs (g2)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,p; //  n*m, p: 플레이어 수
int s[10]; // idx 플레이어의 확장할 수 있는 칸의 수
int canExtend[1001][1001];
int vis[1001][1001];

queue<tuple<int,int,int>> q[10]; // x,y,step

int direct[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int res[10];

bool InRange(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs() {

    while (1) {
        bool isExtend = 0;

        // player 순차적으로 
        for (int i=1;i<=p;i++) {
            queue<tuple<int,int,int>> nextq; // 다음턴

            while (!q[i].empty()) {
                int curx,cury,curstep;
                tie(curx,cury,curstep) = q[i].front();  q[i].pop();

                if (curstep>=s[i]) {
                    nextq.push({curx,cury,0});
                    continue;
                }

                for (int dir=0;dir<4;dir++) {
                    int nx = curx + direct[dir][0];
                    int ny = cury + direct[dir][1];
                    
                    if (!InRange(nx,ny))    continue;
                    if (!canExtend[nx][ny])    continue;

                    canExtend[nx][ny] = 0;
                    q[i].push({nx,ny,curstep+1});
                    res[i]++;
                    isExtend=1;
                }
            }

            q[i] = nextq;
        }

        if (!isExtend)  break;
    }
}
void solution() {
    // init
    cin >> n >> m >> p;
    for (int i=1;i<=p;i++)
        cin >> s[i];
    for (int i=0;i<n;i++) {
        string row;
        cin >> row;
        for (int j=0;j<m;j++) {
            if (row[j]=='.')
                canExtend[i][j] = 1; // 빈 칸
            else if (row[j]=='#')
                canExtend[i][j] = 0; // 벽
            else {
                int player = row[j]-'0';
                canExtend[i][j] = 0; // 플레이어의 위치
                q[player].push({i,j,0});
                res[player]++;
            }
        }
    }

    bfs();

    for (int i=1;i<=p;i++)
        cout << res[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}