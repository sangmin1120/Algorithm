/*
    압축 풀기
*/
#include <iostream>
using namespace std;

void solution(){
    cout << '\n';
    // input
    int n;
    string str="";

    char c[10];
    int count[10];
    
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> c[i] >> count[i];
    
    for (int i=0;i<n;i++)
        for (int j=0;j<count[i];j++)
            str += c[i];

    // print
    for (int i=0;i<str.size();i++){
        if (i>0 && i%10==0)
            cout << '\n';
        cout << str[i];
    }
    cout << endl;
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