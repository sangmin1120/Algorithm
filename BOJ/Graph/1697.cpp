#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n,k;
int visit[MAX];
int child[3];
int res = 0;

void solve(){
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    visit[n] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int count = q.front().second;
        q.pop();

        if (x == k){
            res = count;
            break;
        }
        child[0] = x-1;
        child[1] = x+1;
        child[2] = 2*x;

        for (int i=0;i<3;i++){
            if (child[i]>=0 && child[i] <MAX && !visit[child[i]]){
                q.push(make_pair(child[i],count+1));
                visit[child[i]] = 1;
            }
        }
    }
    cout << res << endl;
}
int main(){
    cin >> n >> k;

    solve();

    return 0;
}