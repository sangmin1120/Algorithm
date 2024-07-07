#include <iostream>
using namespace std;

int split(int s,int e,int a[]){
    int pivot,right,left;
    left = s+1;
    right = e;
    pivot = a[s];
    
    // left는 pivot보다 작아야한다.
    // right는 pivot보다 커야한다.
    while( left<=right){
        while ((a[right] >= a[pivot]) && (left<=right))
            right--;
        
        while((a[left] <= a[pivot]) && (left<=right))
            left++;
        
        if (left<=right)
            swap(a[left],a[right]);
    }

    swap(a[right],a[s]);
    // pivot 인덱스를 리턴
    return right;
}
void quick_sort(int s , int e , int a[]){
    if (s>=e)
        return;
    
    int m = split(s,e,a);
    quick_sort(s,m-1,a);
    quick_sort(m+1,e,a);
}