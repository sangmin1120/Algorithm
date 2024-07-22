#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
#define INF 987654321
#define pii pair<int,int>

int n; // 도시의 수
int m; // 버스 수
vector<pii> graph[MAX]; // graph[a] -> (w,b) : a->b 의 w
int dist[MAX];
int pre[MAX]; // pre[a]=b : a의 이전 값은 b이다.
int st,des;

void init(){
    cin >> n;
    cin >> m;

    for (int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back({w,b});
    }
    cin >> st >> des;
    fill(dist,dist+n+1,INF);
}
void solution(){
    priority_queue<pii , vector<pii> , greater<pii>> pq; // (w,v)
    dist[st]=0;
    pre[st]=st;
    pq.push({dist[st],st});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int vertex = cur.second;
        int cost = cur.first;

        if (dist[vertex] != cost)   continue;

        for (auto next : graph[vertex]){
            int next_vertex = next.second;
            int next_cost = next.first;

            if (dist[next_vertex] > dist[vertex]+next_cost){
                dist[next_vertex] = dist[vertex]+next_cost;
                pre[next_vertex] = vertex;
                pq.push({dist[next_vertex],next_vertex});
            }
        }
    }
    
    cout << dist[des] << '\n';

    vector<int> path;
    int cur = des;
    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);

    reverse(path.begin(),path.end());
    cout << path.size() << '\n';
    for (auto x : path) cout << x << ' ';

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}