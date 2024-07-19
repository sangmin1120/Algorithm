#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
#define X first
#define Y second
#define INF 987654321

int r,c;
string map[MAX];

int dist1[MAX][MAX]; // J 이동 거리
int dist2[MAX][MAX]; // F 이동 거리
queue<pair<int,int>> q;
queue<pair<int,int>> f;
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int ans=INF;

void init(){
    cin >> r >> c;

    for (int i=0;i<r;i++){
        fill(dist1[i],dist1[i]+c,-1);
        fill(dist2[i],dist2[i]+c,-1);
    }

    for (int i=0;i<r;i++)
        cin >> map[i];
}
void bfs_q(){

    auto cur = q.front();
    dist1[cur.X][cur.Y]=0;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        // if (cur.X==0 || cur.X==r-1 || cur.Y==0 || cur.Y==c-1){
        //     ans=min(ans,dist1[cur.X][cur.Y]);
        //     return;
        // }

        for (int i=0;i<4;i++){
            int nx = cur.X + direct[i][0];
            int ny = cur.Y + direct[i][1];
            int sec = dist1[cur.X][cur.Y]+1;

            if (nx<0 || nx>=r || ny<0 || ny>=c){
                ans = min(ans,dist1[cur.X][cur.Y]);
                continue;
            }

            if (dist2[nx][ny]!=-1 && (dist2[nx][ny]<=sec || map[nx][ny]=='#'))    continue;

            if (map[nx][ny]=='.' && dist1[nx][ny]==-1){
                dist1[nx][ny] = sec;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
void bfs_f(){

    while(!f.empty()){
        auto cur = f.front();
        f.pop();

        for (int i=0;i<4;i++){
            int nx = cur.X + direct[i][0];
            int ny = cur.Y + direct[i][1];

            if (nx<0 || nx>=r || ny<0 || ny>=c) continue;

            if (map[nx][ny]=='.' && dist2[nx][ny]==-1){
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                f.push(make_pair(nx,ny));
            }
        }
    }
}
void solution(){
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++){
            if (map[i][j] == 'J'){
                q.push(make_pair(i,j));
                dist1[i][j] = 0;
            }
            if (map[i][j] == 'F'){
                f.push(make_pair(i,j));
                dist2[i][j] = 0;
            }
        }

    bfs_f();
    bfs_q();

    

    if (ans==INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans+1 << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}