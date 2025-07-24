/**
 * 감시
 * SIMULATION (G3)
 */
#include <bits/stdc++.h>
using namespace std;

int r,c;
int board1[10][10];
int board2[10][10];
int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // 남,동,북,서
vector<pair<int,int>> cctv;
int res = INT_MAX;

bool OOB(int x,int y) {
    return x<0 || x>=r || y<0 || y>=c;
}
void upd(int x, int y,int dir) {
    dir %= 4;
    while(1) {
        x += direct[dir][0];
        y += direct[dir][1];
        if (OOB(x,y) || board2[x][y]==6)    return; // 벽을 만나면 종료
        if (board2[x][y] != 0)  continue; // 빈칸이 아닐 경우 넘어감
        board2[x][y] = 7;
    }
}
void solution() {

    // 비트를 이용해 방향을 설정한다.
    for (int dirs=0;dirs<(1<<2*cctv.size());dirs++) {

        // board copy
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                board2[i][j] = board1[i][j];

        int brute = dirs;
        for (auto c : cctv) {
            int dir = brute%4;
            brute /= 4; // bit 처리

            int x = c.first;
            int y = c.second;

            switch (board2[x][y])
            {
            case 1:
                upd(x,y,dir);
                break;
            case 2:
                upd(x,y,dir);
                upd(x,y,dir+2);
                break;
            case 3:
                upd(x,y,dir);
                upd(x,y,dir+1);
                break;
            case 4:
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                break;
            case 5:
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
                break;
            }
        }

        // 최소 찾기
        int val = 0;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (board2[i][j]==0)
                    val++;
            }
        }
        res = min(res,val);
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> r >> c;
    for (int i=0;i<r;i++) 
        for (int j=0;j<c;j++) {
            int temp;
            cin >> temp;
            board1[i][j] = temp;
            if (temp>=1 && temp<=5) cctv.push_back({i,j});
        }
    
    solution();

    return 0;
}