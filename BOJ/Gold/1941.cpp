/**
 * 소문난 칠공주 - 가로, 세로 인접할 때, 적어도 S파 4개가 될 수 있는 경우의 수
 * BACKTRACKING + DFS
 */
#include <bits/stdc++.h>
using namespace std;

int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // 동,서,남,북

char boards[5][5];
int visited[5][5];
int n = 5; // 5 X 5
int res = 0;

bool InRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}
void bt(int x, int y, int count, int S_count) {
    // exit cond
    if (count==7) {
        if (S_count>=4) {
            res++;
        }
        return;
    }

    //logic
    for (int i=0;i<4;i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];

        if (!InRange(nx,ny))    continue;

        if (!visited[nx][ny]) {
            visited[nx][ny] = 1;
            if (boards[nx][ny]=='S')
                bt(nx,ny,count+1,S_count+1);
            else
                bt(nx,ny,count+1,S_count);
            visited[nx][ny] = 0;
        }
    }
}
void solution() {

    bt(0,0,0,0);

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    for (int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for (int j=0;j<n;j++) {
            if (temp[j]=='S')
                boards[i][j] = 'S';
            else
                boards[i][j] = 'Y';
        }
    }

    solution();

    return 0;
}
