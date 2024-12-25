/*
    N X N 크기의 단어 퍼즐을 만들려고 한다. 입력으로 단어 퍼즐의 모양이 주어진다.
    주어진 퍼즐 모양에서 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수를 출력하는 프로그램을 작성하라.
    흰색 : 1 , 검은색 : 0
*/
#include <iostream>
using namespace std;

void solution(){
    int arr[16][16];
    int n,k;
    cin >> n >> k;

    // input
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> arr[i][j];

    // 가로 확인
    int res=0;
    for (int r=0;r<n;r++)
    {
        int row = 0,col = 0; // row,col 단어 들어갈 수 있는 길이

        for (int c=0;c<n;c++)
        {
            if (arr[r][c]==1){
                row++;
            }
            else{
                if (row==k)
                    res++;
                row=0;
            }

            if (arr[c][r]==1){
                col++;
            }
            else{
                if (col==k)
                    res++;
                col=0;
            }
        }

        if (row==k) res++;
        if (col==k) res++;
    }
    cout << res << endl;
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