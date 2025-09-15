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
int graph[INF_MAX][INF_MAX]; // v -> u 의 w 가중치
int result

void solution() {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> v >> e;
    cin >> start;
    for (int i=0;i<e;i++) {
        int a,b,w;  cin >> a >> b >> w;
        graph[a][b] = w;
    }

    solution();

    return 0;
}