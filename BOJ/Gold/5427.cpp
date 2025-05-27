/**
 * 불: 불 번지는 것과 탈출 최소 값 경로
 * BFS (g4)
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r,c;
int boards[1001][1001];
int visited[1001][1001];
int visited_f[1001][1001];

vector<pair<int,int>> pos; // @ - 나의 위치
vector<pair<int,int>> fire_pos; // * - 불의 위치
int direct[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool InRange(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c;
}
void bfs() {

    bool escape = false;

    // 불 번짐을 visited_f 에 저장
    queue<pair<int,int>> f;
    for (auto p : fire_pos){
        f.push(p);
        visited_f[p.X][p.Y] = 1;
    }

    while(!f.empty()) {
        auto cur = f.front();
        f.pop();

        //탐색
        for (int d=0;d<4;d++) {
            int nx = cur.X + direct[d][0];
            int ny = cur.Y + direct[d][1];

            if (!InRange(nx,ny) || visited_f[nx][ny]!=0 || boards[nx][ny]==-1)  continue; //범위 밖, 방문함, 벽

            f.push({nx,ny});
            visited_f[nx][ny] = visited_f[cur.X][cur.Y] + 1;
        }
    }

    // 나 탐색
    queue<pair<int,int>> q;
    auto me = pos.front();
    q.push(me);
    visited[me.X][me.Y] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int nx = cur.X + direct[d][0];
            int ny = cur.Y + direct[d][1];

            if (!InRange(nx,ny)) {
                cout << visited[cur.X][cur.Y] << '\n';
                return;
            }
            if (visited[nx][ny]!=0 || boards[nx][ny]==-1) continue;
            if (visited_f[nx][ny]!=0 && visited[cur.X][cur.Y]+1>=visited_f[nx][ny])    continue;

            q.push({nx,ny});
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
void solution() {

    // init
    fill(&boards[0][0], &boards[1001][0], 0);
    fill(&visited[0][0], &visited[1001][0], 0);
    fill(&visited_f[0][0], &visited_f[1001][0], 0);
    pos.clear();
    fire_pos.clear();

    cin >> c >> r;
    for (int i=0;i<r;i++) {
        string s;
        cin >> s;
        for (int j=0;j<s.length();j++) {
            char temp  = s[j];
            if (temp=='.')  boards[i][j] = 0;
            else if (temp=='#') boards[i][j] = -1;
            else if (temp=='@') {
                pos.push_back({i,j});
                boards[i][j] = 0;
            }
            else if (temp=='*') {
                fire_pos.push_back({i,j});
                boards[i][j] = 0;
            }
        }
    }

    //bfs
    bfs();
}
int main() {

    int test_case;
    cin >> test_case;

    while (test_case--) {
        solution();
    }

    return 0;
}