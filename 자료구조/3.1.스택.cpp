#include <iostream>
using namespace std;
// 스택 (리스트로 구현)
class stack{
    int size;
    int *items;
    int top;
    private:
        void CreateStack( int _size );
        bool is_empty();
        bool is_full();
        void push(int item);
        int pop();
};
// 생성
void stack::CreateStack(int _size){
    size = _size;
    items = new int[size];
    top=0;
}
// is_empty
bool stack::is_empty(){
    return (top==0);
}
// is_full
bool stack::is_full(){
    return (top==size);
}
// push
void stack::push(int item){
    if (is_full){
        cout << "Pushing in full stack\n";
        return;
    }
    items[top++] = item;
}
// pop
int stack::pop(){
    if (is_empty){
        cout << "Poping in empty stack\n";
        return;
    }
    return items[--top];
}