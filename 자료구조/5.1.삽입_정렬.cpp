#include <iostream>
using namespace std;

void insert(int x, int n ,int b[]){
    // ������ ��ġ ã��
    for (int i=0;i<n;i++){
        if (b[i] >= x){
            // ���� ��ġ �����
            for (int j=n-1;j>=i;j--)
                b[j] = b[j-1];
            b[i] = x;
            break;
        }
    }
}
void insertion_sort(int n,int a[]){
    int i;

    for (int i=1;i<=n;i++)
        insert(a[i],i+1,a);
}