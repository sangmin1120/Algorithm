#include <iostream>
using namespace std;
//Å¥
class queue{
    int size;
    int* items;
    int front,rear;
    
    private:
        void CreateQueue(int _size);
        bool is_empty();
        bool is_full();
        void enqueue(int item);
        int dequeue();
};
// »ý¼º
void queue::CreateQueue(int _size){
    size = _size;
    items = new int[size];
    front = rear = -1;
}
// is_empty
bool queue::is_empty(){
    return (front==rear);
}
// is_full
bool queue::is_full(){
    return (rear==size-1);
}
// push
void queue::enqueue(int item){
    if (is_full()){
        cout << "Cannot add an element to a full queue\n";
        return;
    }
    items[++rear] = item;
}
// pop
int queue::dequeue(){
    if (is_empty()){
        cout << "Cannot delete an element to a empty queue\n";
        return;
    }

    return items[++front];
}
