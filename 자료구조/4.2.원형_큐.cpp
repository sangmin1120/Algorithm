#include <iostream>
using namespace std;
// 원형 큐
class queue{
    int size;
    int* items;
    int front,rear;
    int count;
    
    private:
        void CreateQueue(int _size);
        bool is_empty();
        bool is_full();
        void enqueue(int item);
        int dequeue();
};
//생성
void queue::CreateQueue(int _size){
    size = _size;
    items = new int[size];
    front = rear = -1;
    count = 0;
}
// is_empty
bool queue::is_empty(){
    return (count==0);
}
// is_full
bool queue::is_full(){
    return (count==size);
}
// push
void queue::enqueue(int item){
    if (is_full()){
        cout << "Cannot add an element to a full queue\n";
        return;
    }
    rear = (rear+1)%size;
    items[rear] = item;
    count++;
}
// pop
int queue::dequeue(){
    if (is_empty()){
        cout << "Cannot delete an element to a empty queue\n";
        return;
    }
    front = (front+1)%size;
    count--;
    return items[front];
}