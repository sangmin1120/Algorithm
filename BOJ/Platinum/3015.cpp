/**
 * 오아시스 재결합:
 * stack (p5)
 */
#include <bits/stdc++.h>
using namespace std;

void solution() {

    //init
    int n;
    cin >> n;
    int ans=0;

    int arr[n+1];
    for (int i=0;i<n;i++) cin >> arr[i];

    for (int i=0;i<n;i++) {

        int bet_max = INT_MIN;
        int bet_min = INT_MAX;

        for (int j=i+1;j<n;j++) {

            if (arr[i] < arr[j]) {
                if (arr[j] > bet_max) {
                    ans++;
                    bet_max = arr[j];
                }
            }
            else if (arr[i] > arr[j]) {
                if (arr[j] > bet_max) {
                    ans++;
                    bet_max = 
                }
            }       
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}