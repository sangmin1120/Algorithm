#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 20001
using namespace std;

int n,e;
vector <pair<int,int>> arr[MAX];
int dist[MAX];
int start;

void solve(){
    priority_queue<pair <int,int>> pq;
    pq.push(make_pair(0,start)); // weight, start_vertex
    dist[start] = 0;

    while (!pq.empty()){
        int vertex = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i=0;i<arr[vertex].size();i++){
            int next = arr[vertex][i].first;
            int next_cost = arr[vertex][i].second;

            if (dist[next] > cost+next_cost){ // alarm clock
                dist[next] = cost+next_cost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
}
int main(){
    cin >> n >> e; // vertex 수와 edge 수
    cin >> start;

    for (int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b,c));
    } // 입력 받기

    for (int i=1;i<=n;i++)
        dist[i] = INF; // 무한 대로 초기화
    solve();

    for (int i=1;i<=n;i++){
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}