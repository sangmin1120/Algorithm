#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int n,k;
int dist[MAX];
queue<int> q;

void init(){
    
    cin >> n >> k;

    fill(dist,dist+MAX,-1);

}
void bfs(){
    dist[n] = 0;
    q.push(n);

    while(!q.empty()){
        int point = q.front();
        q.pop();

        for (int next : {point-1,point+1,point*2}){
            if (next<0 || next>MAX) continue;
            if (dist[next] != -1)   continue;

            dist[next] = dist[point]+1;
            // cout << next << " : " << dist[next] << '\n';
            q.push(next);
        }
    }
}
void solution(){

    bfs();

    cout << dist[k] << endl;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}