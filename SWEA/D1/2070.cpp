/*
    2개의 수를 입력 받아 크기를 비교하여 등호 또는 부등호를 출력하는 프로그램을 작성하라.
*/
#include <iostream>
using namespace std;

void solution(){
    int a,b;
    cin >> a >> b;

    if (a<b)    cout << '<';
    else if (a>b)   cout << '>';
    else    cout << '=';

    cout << endl;
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