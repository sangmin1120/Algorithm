#include <iostream>
using namespace std;

int test_case;
int w,h;
char arr[501][501];
int first_idx[2];
int second_idx[2];
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void input(){
    cin >> h >> w;

    first_idx[0] = w+1;
    first_idx[1] = h+1;
    second_idx[0] = w+1;
    second_idx[1] = h+1;

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

void solution(){
    
}
int main(){
    cin >> test_case;

    for (int i=0;i<test_case;i++){
        input();
        solution();
    }

}