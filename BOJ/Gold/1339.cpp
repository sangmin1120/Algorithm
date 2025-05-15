/**
 * 단어 수학: GCF+ACDBE 임의의 숫자로 합이 최대 만들기
 * greedy
 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string input;
int letter_count[10] = {0};

bool cmp(int a,int b){
    return a>b;
}
void solution(){
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        int val = 1;
        for (int j=s.size()-1;j>=0;j--){
            letter_count[s[j]-'A'] += val;
            val *= 10;
        }
    }

    sort(letter_count,letter_count+10,cmp);

    int sum = 0;
    int num = 9;
    for (int i=0;i<10;i++){
        sum += letter_count[i]*num;
        num--;
    }

    cout << sum << endl;

}
int main(){
    cin >> n;
    
    solution();

    return 0;
}