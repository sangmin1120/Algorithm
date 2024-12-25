/*
    간단한 소인수 분해 : n = 2^a * 3^b * 5^c * 7^d * 11^e
*/
#include <iostream>
using namespace std;
#define SIZE 5

int numbers[SIZE]={2,3,5,7,11};

void solution(){
    // init
    int n;
    int res[SIZE] = {0}; // a,b,c,d,e;
    
    // input
    cin >> n;

    while (n>1){

        for (int i=0;i<SIZE;i++){
            if (n%numbers[i] == 0){
                res[i]++;
                n /= numbers[i];
            }
        }
    }

    for (int i=0;i<SIZE;i++)
        cout << res[i] << ' ';
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