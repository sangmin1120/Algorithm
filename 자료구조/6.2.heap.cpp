#include <iostream>
#include <algorithm>
using namespace std;

int *heap; // index�� 1���� ���� �ִ�_��
int cnt; // heap�� count

// ����� �籸��
void heapify_topdown(int idx){

    // leaf node�̸� ����
    if (2*idx >= cnt)
        return;
    
    if (2*idx==cnt){
        if (heap[idx] < heap[2*idx]){
            swap(heap[idx],heap[2*idx]);
        }
        return;
    }

    if (heap[2*idx+1]>heap[2*idx] && heap[2*idx+1]>heap[idx]){
        swap(heap[idx],heap[2*idx+1]);
        heapify_topdown(2*idx+1);
    }
}

// ����� �籸��
void heapify_bottomup(int idx){

    // root node�� �����ϸ� ��
    if (idx == 1)
        return;
    
    if (heap[idx/2] < heap[idx]){
        swap(heap[idx/2],heap[idx]);
        heapify_bottomup(idx/2);
    }
}

// push
void push(int ndata){
    cnt++;
    heap[cnt] = ndata;

    heapify_bottomup(cnt);
}

// pop
int pop(){
    int temp = heap[1];
    heap[1] = heap[cnt];
    cnt--;

    heapify_topdown(1);
}