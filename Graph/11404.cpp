#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define INF 987654321
using namespace std;

int n,m;
vector<pair<int,int>> v[MAX];
vector<int> dist[MAX];

void solve(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (dist[i][j] == INF)
                cout << '0' << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    cin >> n;
    cin >> m;

    // dist �ʱ�ȭ
    for (int i=1;i<=n;i++){
        dist[i].resize(n);
        for (int j=1;j<=n;j++){
            if (i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // edge �Է�
    for (int i=1;i<=m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));       // a���� b���� c���
        dist[a][b] = min(dist[a][b],c);  // ���� ���� ���� �� �� �� ����.
    }

    solve();
    return 0;
}