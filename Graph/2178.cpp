#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102];

int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void init(){
    cin >> n >> m;

    for (int i=0;i<n;i++)   cin >> board[i];
    for (int i=0;i<n;i++)   fill(dist[i],dist[i]+m,-1);

}
void solution(){

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for (int i=0;i<4;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (dist[nx][ny]>=0 || board[nx][ny] != '1')    continue;

            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push(make_pair(nx,ny));
        }
    }

    cout << dist[n-1][m-1]+1 << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}