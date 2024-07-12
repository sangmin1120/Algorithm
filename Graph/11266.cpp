#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertices,edges;
vector<int> graph[10001];

int dfn[10001];
int low[10001];
int num;

vector<int> articulation;
int ans;

void init(){
    cin >> vertices >> edges;

    for (int i=0;i<edges;i++){
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    fill(dfn, dfn + vertices + 1, -1);
    fill(low, low + vertices + 1, -1);
    num = 0;
    ans = 0;
}
void dfs(int u , int v){ // v는 u의 부모
    dfn[u] = low[u] = ++num;

    for (int i=0;i<graph[u].size();i++){
        int next = graph[u][i];

        if (dfn[next]<=0){
            dfs(next,u);

            low[next] = min(low[u],low[next]);
            if (low[next] >= dfn[u]){
                ans++;
                articulation.push_back(u);
            }
        }
    }
}
int main(){
    init();

    dfs(1,0);

    // for (int i=1;i<=vertices;i++)  
    //     cout << i << ':' << dfn[i] << ':' << low[i] << '\n';

    sort(articulation.begin(),articulation.end());
    articulation.erase(unique(articulation.begin(),articulation.end()),articulation.end());

    cout << ans << '\n';
    for (int i=0;i<articulation.size();i++)
        cout << articulation[i] << ' ';
    return 0;
}