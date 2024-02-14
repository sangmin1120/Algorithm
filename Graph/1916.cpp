#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 987654321
using namespace std;

int n,m;
vector<pair<int,int>> arr[MAX];
int start,arrive;
int dist[MAX];

void solve(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start)); // -weight, vertext
    dist[start] = 0;

    while(!pq.empty()){
        int v = pq.top().second;
        int cost = -pq.top().first; //(-1) 주의
        pq.pop(); 

        // v까지 cost가 갱신이 안되었다. 그러므로 확인할 필요X
        // 이미 갱신 되어있는 값이 pq에 들어가 있다.
        if (dist[v] < cost) continue;

        for (int i=0;i<arr[v].size();i++){
            int next = arr[v][i].first;
            int next_cost = arr[v][i].second;

            if (dist[next] > cost+next_cost){
                dist[next] = cost+next_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
}
int main(){
    cin >> n;
    cin >> m;

    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        
        arr[a].push_back(make_pair(b,c)); // arr[source].(sink,weight);
    }

    cin >> start >> arrive;
    // dist 값 무한대로 초기화
    for (int i=1;i<=n;i++)
        dist[i] = INF;
    if (start == arrive){
        cout << '0' << endl;
        return 0;
    }
    solve();

    cout << dist[arrive] << endl;
    return 0;
}