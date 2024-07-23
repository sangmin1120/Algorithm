#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 987654321

int n;
int m;
int dist[MAX][MAX];

void init(){
    cin >> n;
    cin >> m;

    for (int i=1;i<=n;i++){
        fill(dist[i],dist[i]+1+n,INF);
    }

    for (int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b],w);
    }

    for (int i=1;i<=n;i++)
        dist[i][i]=0;

}
void solution(){

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (dist[i][j]==INF)    cout << "0 ";
            else    cout << dist[i][j]  << ' ';
        }
        cout << '\n';
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