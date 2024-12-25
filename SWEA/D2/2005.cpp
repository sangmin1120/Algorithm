/*
    크기가 N인 파스칼의 삼각형을 만들어야 한다.
*/
#include <iostream>
#include <vector>
using namespace std;

void solution(){
    int n;
    cin >> n;

    int v[11][11];
    v[1][1] = 1;
    for (int i=2;i<=n;i++) // row
    {
        for (int j=1;j<=i;j++) // col
        {
            if (j==1 || j==i)   v[i][j] = 1;
            else    v[i][j] = v[i-1][j-1]+v[i-1][j];
        }
    }

    // vector print
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
}
int main(int argc,char** argv){
    	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << '\n';
        solution();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}