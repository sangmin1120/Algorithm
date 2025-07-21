/**
 * 트리 : 트리의 개수 세기
 * TREE (G4)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
int test_number;
vector<int> graph[501];
int visited[501];
bool isTree;

void dfs(int cur,int prev) {

    for (auto next : graph[cur]) {
        if (prev == next)   continue; // 이전 노드이면 pass

        if (visited[next]) { // 트리는 방문한 노드를 다시 방문하면 안된다. No Cycle
            isTree = false;
            continue;
        }
        visited[next] = 1;
        dfs(next,cur);
    }
}
void solution() {

    int tree_size = 0;

    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        isTree=true;
        dfs(i,-1);
        tree_size += isTree;
    }

    // print
    cout << "Case " << test_number << ": ";
    if (tree_size==0)  cout << "No trees." << '\n';
    else if (tree_size==1)   cout << "There is one tree." << '\n';
    else if (tree_size>1)   cout << "A forest of " << tree_size << " trees." << '\n';
    test_number++;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    test_number = 1;
    while(1) {
        cin >> n >> m;
        if (n==0 && m==0)   break;

        // 초기화
        for (int i=0;i<=n;i++) {
            graph[i].clear();
            visited[i] = 0;
        }

        for (int i=0;i<m;i++) {
            int v1,v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        solution();
    }
    
    return 0;
}