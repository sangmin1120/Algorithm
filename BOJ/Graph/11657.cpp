#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501
#define INF 987654321

int n,m;
int graph[MAX][MAX]; // a->b의 가중치
int dist[MAX][MAX];

void init(){
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        fill(dist[i],dist[i]+n,INF);
        fill(graph[i],graph[i]+n,INF);
    }
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;

        dist[a][b] = c;
    }
}
void floyd(){

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
            }
        }
    }
}
void solution(){

    floyd();

    for (int i=2;i<=n;i++)
        cout << dist[1][i] << '\n';
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    solution();

    return 0;
}