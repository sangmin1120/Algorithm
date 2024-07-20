#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int n;
int arr[MAX];
int target;
int res = 0;

void solution(){
    // 정렬
    sort(arr,arr+n);

    int s = 0;
    int e = n-1;
    // target을 기준으로 s , e를 조절한다. (Two pointer)
    while (s<e){
        int sum = arr[s] + arr[e];
        if (sum < target)
            s++;
        else if (sum > target)
            e--;
        else if (sum == target){
            res++;
            e--;
        }
    }
    cout << res << endl;
}
int main(){
    // input & init
    cin >> n;
    for (int i=0;i<n;i++)   cin >> arr[i];
    cin >> target;

    solution();

    return 0;
}
