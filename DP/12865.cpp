#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
#define INF 100001
using namespace std;

int n,capacity;
int w[MAX]; // weight
int p[MAX]; // profit
vector<vector<int>> res;

void solve(){
    res[0].resize(capacity+1);
    for (int i=1;i<=n;i++){
        res[i].resize(capacity+1);
        for (int j=1;j<=capacity;j++){
            if (j>=w[i])
                res[i][j] = max(res[i-1][j],res[i-1][j-w[i]]+p[i]);

            res[i][j] = max(res[i][j],res[i-1][j]);
        }
    }
}
int main(){
    cin >> n >> capacity;
    res.resize(n+1);

    for (int i=1;i<=n;i++){
        cin >> w[i] >> p[i];
    }

    solve();

    cout << res[n][capacity] << endl;
    return 0;
}