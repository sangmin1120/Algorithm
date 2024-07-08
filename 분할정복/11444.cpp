#include <iostream>
#include <map>
using namespace std;

#define MOD 1000000007

map<long long , long long> f;
long long n;

void init(){
    cin >> n;
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
}
long long fib(long long k){
    if (k<=2)   return f[k];

    if (f.count(k)>0)   return f[k];

    // Â¦¼ö
    if (k%2==0){
        long long m = k/2;
        long long temp1 = fib(m);
        long long temp2 = fib(m-1);
        f[k] = (temp1 * (2*temp2+temp1))%MOD;
    }
    // È¦¼ö
    else{
        long long m = (k+1)/2;
        long long temp1 = fib(m);
        long long temp2 = fib(m-1);
        f[k] = (temp1*temp1 + temp2*temp2)%MOD;
    }

    return f[k];
}
void solution(){
    cout << fib(n) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    solution();

    return 0;
}