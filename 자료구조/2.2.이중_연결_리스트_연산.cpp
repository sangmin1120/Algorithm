#include <iostream>
using namespace std;

// 이중 연결 리스트
class node{
    int item;
    node *llink , *rlink;
    private:
        void insert(int item);
        void remove(int item);
};

// 1. 추가
void node::insert(int item){
    // 적절한 위치 찾기
    node *curr = this;
    while(curr->rlink != NULL){
        if (curr->item > item)
            break;
    }
    
    // 노드 생성
    node *nnode;
    nnode->item = item;

    // link 갱신
    // 1) rlink
    nnode->rlink = curr->rlink;
    curr->rlink = nnode;
    // 2) llink
    nnode->llink = curr;
    nnode->rlink->llink = nnode;
}

// 2. 제거
void node::remove(int val){
    // 원소 찾기
    node *curr = this;
    while(curr->rlink != NULL){
        if (curr->rlink->item == val)
            break;
    }

    // link 분리
    node *dnode = curr->rlink;
    // 1) rlink
    curr->rlink = dnode->rlink;
    // 2) llink
    curr->rlink->llink = curr;

    // free
    free(dnode);
}