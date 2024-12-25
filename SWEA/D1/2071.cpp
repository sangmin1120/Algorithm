/*
    10개 숫자의 평균 구하기
*/
#include <iostream>
#include <cmath>
using namespace std;

void solution(){
    
    int n=10;
    int num,sum=0;
    for (int i=0;i<n;i++){
        cin >> num;
        sum += num;
    }

    cout << round(sum/(double)n) << endl;
}

int main(int argc,char** argv){
    int test_case;
    int T;

    //freopen("input.txt","r",stdin);

    cin >> T;
    for (test_case=1;test_case<=T;test_case++){
        cout << "#" << test_case << ' ';    
        solution();

    }

    return 0;
}