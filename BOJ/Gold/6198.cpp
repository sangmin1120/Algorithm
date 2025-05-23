/**
 * 옥상 정원 꾸미기: 오른쪽에 나보다 큰수 몇개 있나
 * stack (g5) - h < top 이면 stack 내부에 있는 것들은 모두 h 까지 볼 수있다. -> 그래서 size를 더하는 것이다.
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

void solution() {

    // init
    int n;
    cin >> n;

    long long ans=0;
    stack<int> s;

    while(n--) {
        int h;
        cin >> h;

        while (!s.empty() && s.top() <= h)
            s.pop();
        
        ans += s.size();
        s.push(h);
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}