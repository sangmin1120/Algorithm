/**
 * 트리 순회 : 전위, 중위, 후의 탐색 - 루트를 기준으로 바뀜
 * TREE S1
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30]; // left child
int rc[30]; // right child

/**
 * 전위 탐색 - (루트)(왼쪽 자식)(오른쪽 자식)
 */
void preorder(int cur) {
    cout << char(cur+'A'-1);
    if (lc[cur]!=0) preorder(lc[cur]);
    if (rc[cur]!=0) preorder(rc[cur]);
}
/**
 * 중위 탐색 - (왼쪽 자식)(루트)(오른쪽 자식)
 */
void inorder(int cur) {
    if (lc[cur]!=0) inorder(lc[cur]);
    cout << char(cur+'A'-1);
    if (rc[cur]!=0) inorder(rc[cur]);
}
/**
 * 후위 탐색 - (왼쪽 자식)(오른쪽 자식)(루트)
 */
void postorder(int cur) {
    if (lc[cur]!=0) postorder(lc[cur]);
    if (rc[cur]!=0) postorder(rc[cur]);
    cout << char(cur+'A'-1);
}
void solution() {

    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1);   cout << '\n';
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    cin >> n;
    for (int i=0;i<n;i++) {
        char node,left,right;
        cin >> node >> left >> right;

        if (left!='.')  lc[node-'A'+1] = left-'A'+1;
        if (right!='.') rc[node-'A'+1] = right-'A'+1;
    }

    solution();

    return 0;
}