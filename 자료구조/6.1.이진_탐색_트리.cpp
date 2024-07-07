#include <iostream>
using namespace std;

// 초기화
typedef class node *nptr;
class node{
    int key;
    nptr lchild , rchild;

    private:
        void search(int x);
        void insert(int x);
        int remove(int x);
        int get_max(){
            if (this->rchild!=NULL)
                return this->rchild->get_max();
            else
                return this->key;
        }
};

// 검색
void node::search(int x){
    
    //찾음
    if (x == this->key){
        cout << "Bingo!!\n";
    }

    // x가 작아
    else if (x < this->key){
        if (this->lchild != NULL)
            this->lchild->search(x);
        else
            cout << "Not found\n";
    }

    // x가 커
    else{
        if (this->rchild != NULL)
            this->rchild->search(x);
        else
            cout << "Not found\n";
    }
}

// 추가
void node::insert(int x){
    // degenerate case (tree가 비어있음)
    if (this->key == -1){
        this->key = x;
        return;
    }

    // x와 key가 같을 때
    if (x==this->key)
        cout << "No duplicate data\n";
    
    // x가 더 작아
    else if(x<this->key){
        if (this->lchild != NULL)
            this->lchild->insert(x);
        else{
            this->lchild = (nptr)malloc(sizeof(node));
            this->lchild->key = x;
            this->lchild->lchild = this->lchild->rchild = NULL;
        }
        
    }

    // x가 더 커
    else{
        if (this->rchild != NULL)
            this->rchild->insert(x);
        else{
            this->rchild = (nptr)malloc(sizeof(node));
            this->rchild->key = x;
            this->rchild->lchild = this->rchild->rchild = NULL;
        }
    }

}

// 제거
int node::remove(int x){

    // 찾음
    if (x==this->key){

        // 1. leaf node
        if (this->lchild==NULL && this->rchild==NULL){
            return 1;
        }
        // 2. lchild만 NULL
        if (this->lchild==NULL && this->rchild!=NULL){
            this->key = this->rchild->key;
            this->lchild = this->rchild->lchild;
            this->rchild = this->rchild->rchild;
            return 0;
        }
        // 3. rchild만 NULL
        if (this->lchild!=NULL && this->rchild==NULL){
            this->key = this->lchild->key;
            this->rchild = this->lchild->rchild;
            this->lchild = this->lchild->lchild;
            return 0;
        }
        // 4. 둘 다 NULL이 아니야
        if (this->lchild!=NULL && this->rchild!=NULL){
            this->key = this->lchild->get_max();
            if (this->lchild->remove(this->key) == 1)
                this->lchild = NULL;
            return 0;
        }
    }
    // x가 더 작아
    else if (x < this->key){
        if (this->lchild != NULL){
            // 참이면 자식이 삭제 요청을 보냄
            // 그래서 부모는 NULL값으로 바꿔줌
            if (this->lchild->remove(x) == 1)
                this->lchild = NULL;
        }
        else
            cout << "Not found\n";
        return 0;
    }
    
    // x가 더 커
    else{
        if (this->rchild != NULL){
            if (this->rchild->remove(x) == 1)
                this->rchild = NULL;
        }
        else
            cout << "Not found\n";
        return 0;
    }
}