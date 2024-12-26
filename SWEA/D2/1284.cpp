/*
    수도 요금 경쟁 : 더 싼 요금 출력
*/
#include <iostream>
using namespace std;

void solution(){
    // init & input
    int p,q,r,s;
    int w;
    cin >> p >> q >> r >> s >> w;

    // solution
    int res = p*w;
    int sum = q;
    if (r < w){
        sum += (w-r)*s;
    }
    if (res > sum)  res = sum;
    cout << res << '\n';
}
int main(int argc,char** argv){
    	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << ' ';
        solution();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}