/**
 * 트리의 부모 찾기
 * 트리 (S2)
 */
#include <bits/stdc++.h>
using namespace std;

int n; // 노드의 수
vector<int> graph[100001]; // 연결되어 있으면 1, 아니면 0
int parent[100001]; // idx의 부모를 저장

void dfs(int vertex) {

    for (auto ver : graph[vertex]) {
        // 아직 방문 안했으면 방문
        if (!parent[ver]) {
            parent[ver] = vertex;
            dfs(ver);
        }
    }
}
void solution() {

    dfs(1);

    // print
    for (int i=2;i<=n;i++)
        cout << parent[i] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> n;
    for (int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        // 양방향 연결
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solution();

    return 0;
}