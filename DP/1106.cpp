#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 1001

int goal,n;
vector<int> cost;
vector<int> gain;
int dp[1001];

void init(){
    cin >> goal >> n;

    cost.resize(n);
    gain.resize(n);

    for (int i=0;i<n;i++){
        cin >> cost[i] >> gain[i];
    }

    for (int i=0;i<=goal;i++)   dp[i] = INF;

    for (int i=0;i<n;i++){
        for (int k=0;k*gain[i]<=goal;k++){
            if (dp[k*gain[i]]==INF || dp[(k-1)*gain[i]]==INF)
                dp[k*gain[i]] = cost[i]*k;
            else
                dp[k*gain[i]] = min(dp[k*gain[i]] , cost[i]*k);
        }
    }

    for (int i=0;i<=goal;i++)   cout << i << ':' << dp[i] << '\n';
}
void memoization(){

    for (int i=0;i<n;i++){
        for (int k=0;k<=goal;k++){
            if (k-gain[i]>=0)
                dp[k] = min(dp[k] , dp[k-gain[i]]+cost[i]);
        }
    }

    for (int i=0;i<=goal;i++)   cout << i << ':' << dp[i] << '\n';
    // cout << dp[goal] << endl;
}
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);

    init();

    memoization();

    return 0;
}