/*
    1부터 N까지의 숫자에서 홀수는 더하고 짝수는 뺐을 때 최종 누적된 값을 구해보자.
*/
#include <iostream>
using namespace std;
int arr[11] = {0};

void solution(){
    for (int i=1;i<=10;i++){
        if (i%2==0)
            arr[i] = arr[i-1] - i;
        else
            arr[i] = arr[i-1] + i;
    }    
}
int main(int argc,char** argv){
    	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;

    solution();

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << ' ';
        int n;
        cin >> n;
        cout << arr[n] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}