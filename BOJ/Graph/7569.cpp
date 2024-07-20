#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX 101
using namespace std;

int row,col,n;
int arr[MAX][MAX][MAX];
int direct[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int visit[MAX][MAX][MAX];
queue<tuple<int,int,int>> q; // z,x,y
int res = 1;

// 좌표 유효성 확인하는 함수
bool check(int z,int x,int y){
    if (z>=0 && z<n && x>=0 && x<row && y>=0 && y<col)  return true;
    return false;
}
void bfs(){
    while(!q.empty()){
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        for (int i=0;i<6;i++){
            int nz = z + direct[i][0];
            int nx = x + direct[i][1];
            int ny = y + direct[i][2];

            if (check(nz,nx,ny) && !visit[nz][nx][ny] && arr[nz][nx][ny] == 0){
                q.push(make_tuple(nz,nx,ny));
                visit[nz][nx][ny] = 1;
                arr[nz][nx][ny] = arr[z][x][y] + 1;
            }
        }
    }
}
// res를 찾아주는 함수
int find_min(){
    for (int i=0;i<n;i++)
        for (int j=0;j<row;j++)
            for (int k=0;k<col;k++){
                if (arr[i][j][k] == 0)
                    return -1;
                res = max(res,arr[i][j][k]);
            }
    return (res==1)?0:res-1;
}
void solution(){

    bfs();

    cout << find_min() << '\n';
}
int main(){
    // input & init
    cin >> col >> row >> n;

    for (int i=0;i<n;i++)
        for (int j=0;j<row;j++)
            for (int k=0;k<col;k++){
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                    q.push(make_tuple(i,j,k));
            }
    
    solution();

    return 0;
}