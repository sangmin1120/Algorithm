/*
패턴에서 반복되는 부분을 마디라고 부른다. 문자열을 입력 받아 마디의 길이를 출력하는 프로그램을 작성하라.
*/
#include <iostream>
#include <vector>
using namespace std;

void solution(){
    int count = 1;
    string str,tmp;
    cin >> str;

    tmp += str[0];
    for (int i=1;i<str.size();i++){
        if (tmp != str.substr(tmp.size(),i)) // tmp.size번째 위치에서 i개 글자 출력
        {
            tmp += str[i];
            count++;
        }
        else{
            break;
        }
    }
    cout << count << endl;
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