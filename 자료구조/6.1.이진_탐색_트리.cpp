#include <iostream>
using namespace std;

// �ʱ�ȭ
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

// �˻�
void node::search(int x){
    
    //ã��
    if (x == this->key){
        cout << "Bingo!!\n";
    }

    // x�� �۾�
    else if (x < this->key){
        if (this->lchild != NULL)
            this->lchild->search(x);
        else
            cout << "Not found\n";
    }

    // x�� Ŀ
    else{
        if (this->rchild != NULL)
            this->rchild->search(x);
        else
            cout << "Not found\n";
    }
}

// �߰�
void node::insert(int x){
    // degenerate case (tree�� �������)
    if (this->key == -1){
        this->key = x;
        return;
    }

    // x�� key�� ���� ��
    if (x==this->key)
        cout << "No duplicate data\n";
    
    // x�� �� �۾�
    else if(x<this->key){
        if (this->lchild != NULL)
            this->lchild->insert(x);
        else{
            this->lchild = (nptr)malloc(sizeof(node));
            this->lchild->key = x;
            this->lchild->lchild = this->lchild->rchild = NULL;
        }
        
    }

    // x�� �� Ŀ
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

// ����
int node::remove(int x){

    // ã��
    if (x==this->key){

        // 1. leaf node
        if (this->lchild==NULL && this->rchild==NULL){
            return 1;
        }
        // 2. lchild�� NULL
        if (this->lchild==NULL && this->rchild!=NULL){
            this->key = this->rchild->key;
            this->lchild = this->rchild->lchild;
            this->rchild = this->rchild->rchild;
            return 0;
        }
        // 3. rchild�� NULL
        if (this->lchild!=NULL && this->rchild==NULL){
            this->key = this->lchild->key;
            this->rchild = this->lchild->rchild;
            this->lchild = this->lchild->lchild;
            return 0;
        }
        // 4. �� �� NULL�� �ƴϾ�
        if (this->lchild!=NULL && this->rchild!=NULL){
            this->key = this->lchild->get_max();
            if (this->lchild->remove(this->key) == 1)
                this->lchild = NULL;
            return 0;
        }
    }
    // x�� �� �۾�
    else if (x < this->key){
        if (this->lchild != NULL){
            // ���̸� �ڽ��� ���� ��û�� ����
            // �׷��� �θ�� NULL������ �ٲ���
            if (this->lchild->remove(x) == 1)
                this->lchild = NULL;
        }
        else
            cout << "Not found\n";
        return 0;
    }
    
    // x�� �� Ŀ
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