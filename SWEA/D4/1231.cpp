/*
    중위 순회 : 이진 트리 탐색
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int n;
char tree[101];

void solution(){
    
}
int main(int argc,char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << ' ';
        solution();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}