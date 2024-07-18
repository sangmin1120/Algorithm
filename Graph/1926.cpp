#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// map을 돌면서 !visit이고 1인 점을 탐색해 bfs
// 최대값을 출력하면 된다.

#define l_MAX 500

int direct[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
vector<vector<int>> map;
vector<vector<int>> visit;
int rows,cols;
int count=0;
int ans=0;

void init(){
    cin >> rows >> cols;

    // allocate
    map.resize(rows+1);
    visit.resize(rows+1);
    for (int r=0;r<rows;r++){
        map[r].resize(cols+1);
        visit[r].resize(cols+1);
    }

    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++){
            cin >> map[i][j];
            visit[i][j]=0;
        }
}
bool check(int y,int x){
    return (x>=0 && x<rows && y>=0 && y<cols);
}
void bfs(int y,int x){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visit[x][y] = 1;
    int val=1;

    while(!q.empty()){
        int x1 = q.front().second;
        int y1 = q.front().first;
        // cout << x << ' ' <<  y << " : " << x1 << " " << y1 << " : " << val << '\n';
        q.pop();

        for (int dir=0;dir<4;dir++){
            int new_x = x1+direct[dir][0];
            int new_y = y1+direct[dir][1];
            

            if (check(new_y,new_x) && map[new_x][new_y]==1 && !visit[new_x][new_y]){
                q.push(make_pair(new_y,new_x));
                
                visit[new_x][new_y]=1;
                val++;
                // cout << x << ':' << y << "(" << new_x << ' ' << new_y << ')' << " val : " << val << '\n';
            }
        }
    }
    if (val > ans)  ans = val;
}
void solution(){

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (map[i][j]==1 && visit[i][j]==0){
                bfs(j,i);
                // cout << i << " : " << j << " : " <<  count << '\n';
                count++;
            }
        }
    }
    cout << count << '\n';
    cout << ans << endl;

}
int main(){
    init();

    solution();

    return 0;
}