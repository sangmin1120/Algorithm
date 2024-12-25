/*
    스토쿠 검증증
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define SIZE 9
int boolean[10] = {0};

int solution(){
    vector<vector<int>> board(SIZE);

    // input
    for (int i=0;i<SIZE;i++){
        board[i].resize(SIZE);
        for (int j=0;j<SIZE;j++)
            cin >> board[i][j];
    }

    // verification
    for (int r=0;r<SIZE;r++){

        memset(boolean,0,sizeof(boolean));
        for (int c=0;c<SIZE;c++){
            if (boolean[board[r][c]] == 1) // fail
                return 0;
            else
                boolean[board[r][c]] = 1;
        }

        memset(boolean,0,sizeof(boolean));
        for (int c=0;c<SIZE;c++){
            if (boolean[board[c][r]] == 1) // fail
                return 0;
            else
                boolean[board[c][r]] = 1;
        }

    }
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            memset(boolean, 0, sizeof(boolean)); // reset boolean array
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (boolean[board[r][c]] == 1) // fail
                        return 0;
                    boolean[board[r][c]] = 1;
                }
            }
        }
    }
    return 1; // success
}
int main(int argc,char** argv){
    	int test_case;
	int T;
	
	// freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << ' ';
        cout << solution() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}