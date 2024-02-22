#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,capacity; // 물품의 수, 배낭 무게
int weight[101];
int value[101];
int dp[101][100001];

void solution(){

    for (int i=1;i<=n;i++){
        for (int j=1;j<=capacity;j++){
            if (j >= weight[i]){
                dp[i][j] = max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]);
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    
    cout << dp[n][capacity];
}
int main(){
    // input & init
    cin >> n >> capacity;
    for (int i=1;i<=n;i++)   cin >> weight[i] >> value[i];

    solution();

    return 0;
}