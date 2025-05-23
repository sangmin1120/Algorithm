/**
 * 내리막 길: 낮은 지점 (0,0)->(n-1,n-1) 이동 경로의 갯수
 * DFS + DP
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int row, col;
vector<vector<int>> arr;
int dp[501][501];
int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check(int x, int y)
{
    if (x < 0 || x >= row || y < 0 || y >= col)
        return false;
    return true;
}
int dfs(int x, int y)
{
    if (x == row - 1 && y == col - 1)
        return 1;
    if (dp[x][y] == -1)
    {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];

            if (check(nx, ny) && arr[x][y] > arr[nx][ny])
                dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}
void solution()
{

    cout << dfs(0, 0) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> row >> col;
    memset(dp,-1,sizeof(dp));
    arr.resize(row);
    for (int i = 0; i < row; i++)
    {
        arr[i].resize(col);
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }

    cout << dfs(0,0) << endl;
    return 0;
}