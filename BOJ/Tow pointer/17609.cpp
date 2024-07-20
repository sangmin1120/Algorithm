#include <iostream>
#include <vector>
using namespace std;

int test_case;
vector<string> v;

int is_palindrome(int left,int right,int Delete,string str){
    while(left < right){
        if (str[left] != str[right]){
            if (Delete == 0){
                if (is_palindrome(left+1,right,1,str) == 0 ||
                    is_palindrome(left,right-1,1,str) == 0)
                    return 1;
                return 2;
            }
            else    return 2;
        }
        else{
            left++;
            right--;
        }
    }
    return 0;
}
void solution(){
    for (int i=0;i<v.size();i++){
        string str = v[i];
        int res = is_palindrome(0,str.length()-1,0,str);
        cout << res << '\n';
    }
}
int main(){
    // input & init
    cin >> test_case;
    for (int i=0;i<test_case;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    solution();

    return 0;
}