/**
 * RGB 거리: 색깔 규칙을 만족하면서 비요으이 최솟값
 * DP
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1001][3];
int r[1001],g[1001],b[1001];

void solution(){
    dp[0][0] = r[0];
    dp[0][1] = g[0];
    dp[0][2] = b[0];

    for (int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+r[i];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+g[i];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+b[i];   
    }

    cout << min({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << '\n';
}
int main(){
    // init & input
    cin >> n;
    for (int i=0;i<n;i++)   cin >> r[i] >> g[i] >> b[i];

    solution();
    
    return 0;
}