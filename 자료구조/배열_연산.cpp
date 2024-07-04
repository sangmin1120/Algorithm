#include <iostream>
using namespace std;

// �ε����� ��ȯ�Ѵ�.

// �˻� (linear_search , binary_search) 
// 1. ���� Ž��
int linear_search(int *arr , int count , int key){
    // �˻�
    for (int i=0;i<count;i++)
        if (arr[i] == key)
            return i;
    
    // �� ã��
    return -1;
}
// 2. ���� Ž�� : ���ĵ� �迭������ ��� ����
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

    // �� ã��
    return -1;
}

// �߰�
void list_insert(int *arr , int count , int key){
    // ������ ��ġ ã��
    int i;
    for (i=0;i<count;i++){
        // ������ ��ġ ã��
        if (arr[i] > key)
            break;
    }

    // �� ���� Ȯ��
    for (int j=count-1;j>=i;j--)
        arr[j+1] = arr[j];
    
    arr[i] = key;
    count++;
}
// ����
void list_delete(int *arr , int count , int key){
    // ���� ã��
    int i;
    for (i=0;i<count;i++)
        if (arr[i] == key)
            break;
    
    // ����
    if (i==count)   return;

    // �����
    for (int j=i;j<count-1;j++)
        arr[j] = arr[j+1];
    count--;
}