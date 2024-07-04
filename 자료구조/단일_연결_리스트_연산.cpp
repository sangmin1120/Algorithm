#include <iostream>
using namespace std;

// 단일 연결 리스트
class node{
    private:
        int item;
        node *link;
    
    public:
        node* search(int item);
        void insert(int item);
        void remove(int item);
};
// 1. 검색
node* node::search(int item){
    node *curr = this;

    while(curr->link != NULL){
        if (curr->item == item)
            return curr;
    }
    return NULL;
}   
// 2. 추가
void node::insert(int item){
    node *curr = this;

    // 1. 적절한 위치 찾기
    while (curr->link != NULL){
        if (curr->item > item)
            break;
    }

    // 2. 새로운 노드 생성
    node *nnode;
    nnode->item = item;
    
    // 3. link 갱신
    nnode->link = curr->link;
    curr->link = nnode;
}
// 3. 제거
void node::remove(int item){
    node *curr = this;

    // 1. 원소 찾기
    while(curr->link != NULL){
        if(curr->item == item)
            break;
    }
    
    // 2. 삭제 노드
    node *dnode = curr->link;
    
    // 3. link 갱신
    curr->link = dnode->link;

    // 4. free
    free(dnode);
}
