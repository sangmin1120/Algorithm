/*
    시 분으로 이루어진 시각을 2개 입력 받아, 더한 값을 시 분으로 출력하는 프로그램을 작성하라.
    (시각은 12시간제로 표시한다. 즉, 시가 가질 수 있는 값은 1시부터 12시이다.)
*/
#include <iostream>
using namespace std;

void solution(){
    int h1,m1,h2,m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int hour = h1 + h2;
    int min = m1 + m2;

    if (min >= 60){
        hour += min/60;
        min %= 60;
    }

    if (hour > 12){
        hour %= 12;
        if (hour==0) hour = 12;
    }

    cout << hour << ' ' << min << endl;
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