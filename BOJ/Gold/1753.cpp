/**
 * 최단 경로: 가중치 10 이하 자연수, 우선 순위 큐?
 * Dijkstra (G4)
 */
#include <bits/stdc++.h>
using namespace std;
#define INF_MAX 20001

// init
int v,e; // vertex의 수, edge의 수
int start;
vector<pair<int,int>> graph[20000]; // v -> u 의 w 가중치
vector<int> visited(20001,INT_MAX);

void solution() {

    priority_queue<pair<int,int>> pq; // weight, v
    visited[start] = 0;
    pq.push({0,start});

    while (!pq.empty()) {
        int cur_dist = - pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int i=0;i<graph[cur_node].size();i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;

            if (next_dist < visited[next_node]){
                visited[next_node] = next_dist;
                pq.push({-next_dist,next_node});
            }
        }
    }

    // printf
    for (int i=1;i<=v;i++) {
        if (visited[i]==INT_MAX)
            cout << "INF" << '\n';
        else
            cout << visited[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> v >> e;
    cin >> start;
    for (int i=0;i<e;i++) {
        int a,b,w;  cin >> a >> b >> w;
        graph[a].push_back({b,w});
    }

    solution();

    return 0;
}