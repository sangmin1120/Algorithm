#include <iostream>
using namespace std;

// ���� ���� ����Ʈ
class node{
    int item;
    node *llink , *rlink;
    private:
        void insert(int item);
        void remove(int item);
};

// 1. �߰�
void node::insert(int item){
    // ������ ��ġ ã��
    node *curr = this;
    while(curr->rlink != NULL){
        if (curr->item > item)
            break;
    }
    
    // ��� ����
    node *nnode;
    nnode->item = item;

    // link ����
    // 1) rlink
    nnode->rlink = curr->rlink;
    curr->rlink = nnode;
    // 2) llink
    nnode->llink = curr;
    nnode->rlink->llink = nnode;
}

// 2. ����
void node::remove(int val){
    // ���� ã��
    node *curr = this;
    while(curr->rlink != NULL){
        if (curr->rlink->item == val)
            break;
    }

    // link �и�
    node *dnode = curr->rlink;
    // 1) rlink
    curr->rlink = dnode->rlink;
    // 2) llink
    curr->rlink->llink = curr;

    // free
    free(dnode);
}