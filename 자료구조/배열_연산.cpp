#include <iostream>
using namespace std;

// 인덱스를 반환한다.

// 검색 (linear_search , binary_search) 
// 1. 선형 탐색
int linear_search(int *arr , int count , int key){
    // 검색
    for (int i=0;i<count;i++)
        if (arr[i] == key)
            return i;
    
    // 못 찾음
    return -1;
}
// 2. 이진 탐색 : 정렬된 배열에서만 사용 가능
int binary_search(int *arr, int count, int key) {
    int s = 0;
    int e = count - 1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }

    // 못 찾음
    return -1;
}

// 추가
void list_insert(int *arr , int count , int key){
    // 적절한 위치 찾기
    int i;
    for (i=0;i<count;i++){
        // 적절한 위치 찾기
        if (arr[i] > key)
            break;
    }

    // 빈 공간 확보
    for (int j=count-1;j>=i;j--)
        arr[j+1] = arr[j];
    
    arr[i] = key;
    count++;
}
// 삭제
void list_delete(int *arr , int count , int key){
    // 원소 찾기
    int i;
    for (i=0;i<count;i++)
        if (arr[i] == key)
            break;
    
    // 예외
    if (i==count)   return;

    // 덮어쓰기
    for (int j=i;j<count-1;j++)
        arr[j] = arr[j+1];
    count--;
}