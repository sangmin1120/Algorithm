/**
 * 숨바꼭질 3: n->k 까지 가장 빠른 시간 구하기
 * bfs (g5)
 */
#include <bits/stdc++.h>
using namespace std;

#define NUM_MAX 100000

int n,k;
int dist[100001];

int direct[2] = {1,-1};
void bfs() {
    priority_queue<int> pq;
    pq.push(n);
    dist[n] = 0;

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();

        if (cur==k || 2*cur==k) {
            cout << dist[cur] << '\n';
            break;
        }

        // 탐색(순간이동)
        int tel = cur*2;
        if (tel<=NUM_MAX && dist[tel]==-1) {
            dist[tel] = dist[cur];
            pq.push(tel);
        }

        // 탐색(이동)
        for (int d : {-1,1}) {
            int nx = cur + d;
            if (nx>=0 && nx<=NUM_MAX && dist[nx]==-1) {
                dist[nx] = dist[cur] + 1;
                pq.push(nx);
            }
        }
    }
}
void solution() {
    //init
    cin >> n >> k;
    fill(dist,dist+100001,-1);

    //solution
    bfs();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}