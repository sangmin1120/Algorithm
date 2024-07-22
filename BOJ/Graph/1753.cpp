#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20001
#define INF 987654321
// directed weight graph
int v,e;
int start;
vector<pair<int,int>> graph[MAX]; // graph[a] = {w,v};
int dist[MAX];

void init(){
    cin >> v >> e;
    cin >> start;

    for (int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(w,b));
    }

    fill(dist,dist+v+1,INF);
}
void solution(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int d=cur.first;
        int idx=cur.second;

        if (dist[idx] != d) continue;

        for (auto next : graph[idx]){
            int next_d = next.first;
            int next_idx = next.second;

            if (dist[next_idx]>dist[idx]+next_d){
                dist[next_idx] = dist[idx]+next_d;
                pq.push(make_pair(dist[next_idx],next_idx));
            }
        }
    }

    for (int i=1;i<=v;i++){
        if (dist[i]==INF)   cout << "INF\n";
        else    cout << dist[i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}