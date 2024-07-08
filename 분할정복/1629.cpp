#include <iostream>
using namespace std;

#define MOD 2147483647

int a, b, c; // a�� b�� ���ϰ� c�� ���� ������

void init() {
    cin >> a >> b >> c;
}

long long DivideQ(int n, int k, int mod) {
    if (k == 0) return 1;

    // ¦�� (even)
    if (k % 2 == 0) {
        long long temp = DivideQ(n, k / 2, mod);
        return temp * temp % mod;
    } else { // Ȧ�� (odd)
        long long temp = DivideQ(n, (k - 1) / 2, mod);
        return temp * temp % mod * n % mod;
    }
}

void solution() {
    cout << DivideQ(a, b, c) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();

    return 0;
}
