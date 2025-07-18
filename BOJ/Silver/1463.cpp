/**
 * 1로 만들기
 * DP (S3)
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000001];

void solution() {

    // dp init
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    // logic
    for (int i=4;i<=n;i++) {
        dp[i] = dp[i-1] + 1;
        if (i%2==0)
            dp[i] = min(dp[i], dp[i/2] + 1);
        if (i%3==0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        
        // cout << i << " : " << dp[i] << '\n';
    }

    cout << dp[n] << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> n;

    solution();

    return 0;
}