/*
    M x M 크기의 파리채를 한 번 내리쳐 최대한 많은 파리를 죽이고자 한다.
    죽은 파리의 개수를 구하라!
    => 누적합 사용
*/
#include <iostream>
using namespace std;

void solution(){
    int n,m; // nxn 배열 에서 mxm 파리채 내려침
    int max=0; // 그때 max

    cin >> n >> m;
    int sum[15][15] = {0,};

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int temp;
            cin >> temp;
            sum[i][j] = temp + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]; // 누적합
        }
    }

    // max 값 찾기
    for (int i=m;i<=n;i++)
    {
        for (int j=m;j<=n;j++)
        {
            int val = sum[i][j] - sum[i-m][j] - sum[i][j-m] + sum[i-m][j-m];
            if (val > max)  max = val;
        }
    }
    cout << max << endl;
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