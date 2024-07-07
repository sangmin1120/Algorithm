#include <iostream>
using namespace std;

int select_min(int s, int e , int b[]){
    int min_idx = s;

    for (int i=s+1;i<=e;i++)
        if (b[i] < b[min_idx])
            min_idx = i;
    return min_idx;
}
void selection_sort(int n , int a[]){
    int i;
    int min_idx;
    for (i=0;i<n;i++){
        min_idx = select_min(i,n-1,a);
        swap(a[i] , a[min_idx]);
    } 
}