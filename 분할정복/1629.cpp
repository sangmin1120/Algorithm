#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

int n,m;
vector<pair<int,int>> weight[1001]; // a에서 b로 가는 가중치
int s , e;
int dist[1001];

void init(){
    cin >> n;
    cin >> m;

    for (int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        weight[a].push_back(make_pair(b,w));
    }
    cin >> s >> e;

    for (int i=0;i<=n;i++)  dist[i] = INF;
    dist[s] = 0;
}

void solution(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        int v = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i=0;i<weight[v].size();i++){
            int next = weight[v][i].first;
            int next_cost = weight[v][i].second;

            if (dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }

    cout << dist[e] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    solution();

    return 0;
}