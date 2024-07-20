#include <iostream>
using namespace std;

int k;
char str[10]; // �ε�ȣ ���ڿ��� �Է¹���
bool check[10]; // ���ڸ� ����ߴ� �� �Ǻ�
string maxr = ""; // ��� max 
string minr = "9876543210"; // ��� min

void dfs(int n , string s){
    if (s.size() == k+1){ // ���� ����
        maxr = max(maxr,s);
        minr = min(minr,s);

        return;
    }
    for (int i=0;i<=9;i++){
        if (check[i] == true)   continue; // �̹� �湮����

        if (str[s.size()-1] == '>'){
            if (s.back()-'0' < i)   continue;
        }

        if (str[s.size()-1] == '<'){
            if (s.back()-'0' > i) continue;
        }

        check[i] = true;
        s.push_back(i+'0');
        dfs(i,s);
        check[i] = false;
        s.pop_back();
    }
}
void solution(){
    string s = "";

    for (int i=0;i<=9;i++){ // ���� ��ü�� �湮
        check[i] = true;
        s.push_back((i+'0'));
        dfs(i,s);
        s.pop_back();
        check[i] = false;
    }

    cout << maxr << '\n' << minr << endl;
}
int main(){
    cin >> k;

    for (int i=0;i<k;i++)   cin >> str[i];

    solution();

    return 0;
}