/*
    10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 프로그램을 작성하라.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define SIZE 10

void solution(){
    vector<int> v(SIZE);

    for (int i=0;i<SIZE;i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    int sum = 0;
    for (int i=1;i<SIZE-1;i++)
        sum += v[i];
    
    cout << round(sum/(double)(SIZE-2)) << endl;
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