#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001
#define X first
#define Y second

int map[MAX][MAX];
int n,m;

queue<pair<int,int>> q;
int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int ans=0;

void init(){
    cin >> m >> n;

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            cin >> map[i][j];
            if (map[i][j]==1)
                q.push(make_pair(i,j));
        }

}
void bfs(){

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for (int i=0;i<4;i++){
            int nx = cur.X + direct[i][0];
            int ny = cur.Y + direct[i][1];

            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (map[nx][ny]==-1 || map[nx][ny]>0)    continue;

            map[nx][ny] = map[cur.X][cur.Y]+1;
            // cout << nx << ' ' << ny << " : " << map[nx][ny] << '\n';
    
            q.push(make_pair(nx,ny));
        }
    }
}
void solution(){

    bfs();

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (map[i][j]==0){
                cout << -1 << endl;
                return;
            }

            ans = max(ans,map[i][j]);
            // cout << map[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << ans-1 << endl;
}
int main(){
    init();

    solution();

    return 0;
}