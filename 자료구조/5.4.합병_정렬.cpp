#include <iostream>
using namespace std;

int n;
int *arr;

void merge(int ls,int le,int rs,int re){
    int lptr = ls , rptr = rs;
    int bptr=0;
    int *brr = (int*)calloc((le-ls)+(re-rs)+2,sizeof(int));

    while( lptr<=le && rptr<=re){
        if (arr[lptr] < arr[rptr])   brr[bptr++] = arr[lptr++];
        else    brr[bptr++] = arr[rptr++];
    }

    if (lptr>le)
        for (int i=rptr;i<=re;i++)  brr[bptr++] = arr[i];
    if (rptr>re)
        for (int i=lptr;i<=le;i++)  brr[bptr++] = arr[i];
    
    arr = brr;
}
void merge_sort(int s , int e){
    // ¿¹¿Ü
    if (s==e)
        return;

    int mid = (s+e)/2;

    // divide
    merge_sort(s,mid);
    merge_sort(mid+1,e);
    
    //conquer
    merge(s,mid,mid+1,e);
}