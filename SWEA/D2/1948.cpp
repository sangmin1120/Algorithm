/*
    날짜 계산기
*/
#include <iostream>
using namespace std;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void solution(){
    // input
    int n;
    int first_month,first_day;
    int second_month,second_day;
    int total = 0;

    cin >> first_month >> first_day >> second_month >> second_day;

    // solution
    if (first_month == second_month)
        total += second_day-first_day+1;
    else{
        total += days[first_month]-first_day+1;
        for (int m=first_month+1;m<second_month;m++){
            total += days[m];
        }
        total += second_day;
    }
    
    cout << total << endl;
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