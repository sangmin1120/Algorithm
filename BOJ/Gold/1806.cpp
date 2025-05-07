/**
 * 부분합: 연속된 수들의 부분합 중 그 합이 S이상이 되는 것 중, 가장 짧은 것
 * 구현
 */
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

int n,s;
int arr[100001];
int res;

void solution(){
    int ep = 0; // start pointer
    int tot = arr[0]; // total

    for (int i=0;i<n;i++){
        while (ep<n && tot<s){
            ep++;
            if (ep != n)    tot+=arr[ep];
        }
        if (ep == n)    break;
        res = min(res,ep-i+1);
        tot -= arr[i];
    }
    if (res == INF) res = 0;
    cout << res << endl;
}
int main(){
    // init & input
    res = INF;
    cin >> n >> s;
    for (int i=0;i<n;i++)   cin >> arr[i];

    solution();

    return 0;
}