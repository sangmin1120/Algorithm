#include <iostream>
using namespace std;

void bubble_sort(int n,int a[]){
    int i,j;

    for (i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if (a[j-1] > a[j])
                swap(a[j-1],a[j]);
        }
    }
}