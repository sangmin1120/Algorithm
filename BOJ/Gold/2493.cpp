/**
 * 탑: 왼쪽에 나보다 큰 애 인덱스 값 찾기
 * stack (g5)
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

void solution() {

    // init
    int n;
    cin >> n;

    stack<pair<int,int>> s;
    s.push({100000001,0});

    for (int i=1;i<=n;i++) {

        int height;
        cin >> height;

        //나보다 큰 애 찾기
        while (s.top().X < height)
            s.pop();
        
        cout << s.top().Y << ' ';
        s.push({height,i});
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}