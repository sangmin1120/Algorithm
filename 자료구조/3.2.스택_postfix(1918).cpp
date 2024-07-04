#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string str;
vector<char> ans;
stack<char> s;

void init() {
    // 초기화
    cin >> str;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void solution() {
    for (char c : str) {
        // operand
        if (c >= 'A' && c <= 'Z') {
            ans.push_back(c);
        }
        // left parenthesis
        else if (c == '(') {
            s.push(c);
        }
        // right parenthesis
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                ans.push_back(s.top());
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop(); 
            }
        }
        // operator
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }

    // 남아있는 거 pop
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    // Print the output
    for (char c : ans) {
        if (c != '(' && c != ')') {
            cout << c;
        }
    }
    cout << endl;
}

int main() {
    init();
    solution();
    return 0;
}
