/**
*  안녕: 인사하면서 체력을 잃고, 기쁨을 얻는다.
*  DP
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> hp;
vector<int> happy;
int dp[101];
void init(){
    cin >> n;

    hp.resize(n);
    happy.resize(n);

    for (int i=0;i<n;i++)   cin>>hp[i];
    for (int i=0;i<n;i++)   cin>>happy[i];

    memset(dp,0,sizeof(int));

    dp[100] = 0;
}
void memoization(){

    for (int i=0;i<n;i++){
        for (int j=100;j>=hp[i];j--){
            dp[j] = max(dp[j] , dp[j-hp[i]]+happy[i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();

    memoization();

    cout << dp[99] << endl;

    return 0;
}