#include <iostream>
using namespace std;

int test_case;
int w,h;
char arr[501][501];
int first_idx[2];
int second_idx[2];
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool check(int x,int y){
    if (x>=0 && x<w && y>=0 && y<h)
        return true;
    return false;
}
void input(){
    cin >> h >> w;

    // �� �˼��� ��ȣ �ε��� �ʱ�ȭ
    first_idx[0] = w+1;
    first_idx[1] = h+1;
    second_idx[0] = w+1;
    second_idx[1] = h+1;

    // �Է� �����鼭 �˼� ��ȣ�� �ε����� �ޱ�
    for (int k=0;k<h;k++)
        for (int j=0;j<w;j++){
            cin >> arr[k][j];
            if (arr[k][j] == '$' && first_idx[0]==w+1 && first_idx[1]==h+1){
                first_idx[0] = k;
                first_idx[1] = j;
            }
            else if (arr[k][j] == '$' && second_idx[0]==w+1 && second_idx[1]==h+1){
                second_idx[0] = k;
                second_idx[1] = j;
            }
        }
}

void dfs(int x,int y){
    for (int c=0;c<4;c++){
        int nx = x + direct[c][0];
        int ny = y + direct[c][1];
        // �� ���ִ� �� ���� Ȯ��
        if (check(nx,ny)){
            // . �����ΰ�?
            if (arr[nx][ny] == '.')
                dfs(nx,ny);
            // # �� �����ΰ�?
            else if (arr[nx][ny] == '#'){
                arr[k][]
            }
        }
    }
}
void solution(){
    
}
int main(){
    cin >> test_case;

    for (int i=0;i<test_case;i++){
        input();
        solution();
    }

}