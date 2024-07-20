#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

#define MAX 100

string str;

void init(){

    getline(cin,str);
}
bool solution(){

    stack<char> s;

    for (auto c : str){
        if (c=='(' || c=='[')   s.push(c);

        else if (c==')'){

            if (s.empty() || s.top()!='(')
                return false;
            s.pop();
        }

        else if (c==']'){

            if (s.empty() || s.top()!='[')
                return false;
            s.pop();
        }
    }

    if (!s.empty()) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        init();

        if (str==".")
            break;

        cout << (solution()==true?"yes":"no") << '\n';
    }
    return 0;
}