#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> v; // start,end ¥„¿ª ∫§≈Õ
int res;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
void solution(){
    sort(v.begin(),v.end(),cmp);

    int e_t = v[0].second;
    res++;

    for (int i=1;i<v.size();i++){
        if (e_t <= v[i].first){
            res++;
            e_t = v[i].second;

        }
    }
    
    cout << res << '\n';
}
int main(){
    // init & input
    cin >> n;
    for (int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        v.push_back(make_pair(s,e));
    }
    res = 0;

    solution();

    return 0;
}