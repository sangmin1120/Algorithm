/**
 * 구간 합 구하기 5: 2쌍의 좌표 안에서 합을 구하기
 * DP
 */
#include <iostream>
#define MAX 1206
using namespace std;

int x1,x2,y1,y2;
int n;
int cnt;
int dp[MAX][MAX];
int temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> cnt;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> temp;
            dp[i][j] = dp[i-1][j]+dp[i][j-1]+temp-dp[i-1][j-1];
        }
    }

    for (int i=0;i<cnt;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1] << '\n';
    }
    return 0;
}
