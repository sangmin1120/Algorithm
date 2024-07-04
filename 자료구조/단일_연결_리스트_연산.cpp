#include <iostream>
using namespace std;

// ���� ���� ����Ʈ
class node{
    private:
        int item;
        node *link;
    
    public:
        node* search(int item);
        void insert(int item);
        void remove(int item);
};
// 1. �˻�
node* node::search(int item){
    node *curr = this;

    while(curr->link != NULL){
        if (curr->item == item)
            return curr;
    }
    return NULL;
}   
// 2. �߰�
void node::insert(int item){
    node *curr = this;

    // 1. ������ ��ġ ã��
    while (curr->link != NULL){
        if (curr->item > item)
            break;
    }

    // 2. ���ο� ��� ����
    node *nnode;
    nnode->item = item;
    
    // 3. link ����
    nnode->link = curr->link;
    curr->link = nnode;
}
// 3. ����
void node::remove(int item){
    node *curr = this;

    // 1. ���� ã��
    while(curr->link != NULL){
        if(curr->item == item)
            break;
    }
    
    // 2. ���� ���
    node *dnode = curr->link;
    
    // 3. link ����
    curr->link = dnode->link;

    // 4. free
    free(dnode);
}
