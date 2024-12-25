/*
    달팽이 숫자
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> numbers;

void solution(){
    int n;
    cin >> n;
    string direction = "right";
    int count = 1;
    int x=0,y=0;

    while(1){
        numbers[x][y] = count;
        count++;

        // direction modify
        if (direction=="right") y++;
        else if (direction=="left") y--;
        else if (direction=="up") x--;
        else if (direction=="down") x++;  

        if (y==n && direction=="right"){
            direction="down";
            y=n-1;
        }
        else if (x==n && direction=="down"){
            direction="left";
            x=n-1;
        }
        else if (y==-1 && direction=="left"){
            direction=="up";
            y=0;
        }
        else if (x==-1 && direction=="up"){
            direction=="right";
            x=0;
        }

        // break
        if (count>=n*n)
            break;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout << numbers[i][j] << ' ';
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