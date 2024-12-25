/*
    거꾸로 읽어도 제대로 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.
    회문이면 1을 출력하고, 아니라면 0을 출력
*/
#include <iostream>
using namespace std;

int solution(){
    string s;
    cin >> s;
    int len = s.size();

    for (int i=0;i<len/2;i++)
    {
        if (s.at(i) != s.at(len-i-1))
            return 0;
    }
    return 1;
}
int main(int argc,char** argv){
    	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << ' ';
        cout << solution() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}