#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> t;
void solution(){
    sort(t.begin(),t.end());

    priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(t[0].second);
    int count = 1;

    for (int i=1;i<t.size();i++){
        if (t[i].first < pq.top()){
            pq.push(t[i].second);
        }
        else{
            pq.pop();
            pq.push(t[i].second);
        }
    }
    cout << pq.size() << '\n';
}   
int main(){
    // input & init
    cin >> n;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        t.push_back(make_pair(a,b));
    }

    solution();

    return 0;
}