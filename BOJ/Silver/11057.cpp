/**
 * 오르막수 : 길이 N의 수에서 오르막 수의 개수 구하기
 * DP (S1) - dp를 2차원 배열 이용 dp[i][j] - i 길이, j로 끝나는 숫자
 * dp[i][j] = dp[i-1][j] + dp[i]][j-1] - dp[i-1][j]는 j와 같은 숫자이지만, dp[i][j-1]은 j-1 대신 j를 넣어 경우의 수를 늘린다.
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][10];
int ans;

void solution() {

    // dp init
    for (int j=0;j<10;j++)
        dp[1][j] = 1;
    
    // logic
    for (int i=2;i<=n;i++) {

        dp[i][0] = dp[i-1][0];
        for (int j=1;j<10;j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;
        }
    }

    for (int j=0;j<10;j++) {
        ans += dp[n][j];
        ans %= 10007;
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;

    solution();

    return 0;
}