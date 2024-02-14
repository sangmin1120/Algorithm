#include <iostream>
#include <algorithm>
#define MAX 401
#define INF 987654321
using namespace std;

int v,e;
int arr[MAX][MAX];
int res = INF;

void solve(){

    for (int k=1;k<=v;k++){
        for (int i=1;i<=v;i++){
            for (int j=1;j<=v;j++){
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}
int main(){
    cin >> v >> e;
    for (int i=1;i<=v;i++){
        for (int j=1;j<=v;j++){
            if (i != j)
                arr[i][j] = INF;
        }
    }

    for (int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    solve();

    for (int i=1;i<=v;i++){
        for (int j=1;j<=v;j++){
            if (i == j) continue;
            res = min(res,arr[i][j] + arr[j][i]);
        }
    }
    cout << (res==INF?-1:res) << endl;
    return 0;
}