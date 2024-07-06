#include <iostream>
using namespace std;
// DEQ
class deq{
    int size;
    int* items;
    int front,rear;

    private:
        void CreateDeq(int _size);
        bool is_empty();
        bool is_full();
        void push_front(int item);
        void push_rear(int item);
        int pop_front();
        int pop_rear();
};
// »ý¼º
void deq::CreateDeq(int _size){
    size = _size;
    items = new int[size];
    front = rear = -1;
}
// is_empty
bool deq::is_empty() {
    return (front == -1);
}
// is_full
bool deq::is_full() {
    return ((front == 0 && rear == size - 1) || (front == rear + 1));
}
// push_front
void deq::push_front(int item) {
    if (is_full()) {
        cout << "Cannot add an element to full deq\n";
        return;
    }

    if (front == -1) { // Empty deque
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front = front - 1;
    }

    items[front] = item;
}
// push_rear
void deq::push_rear(int item) {
    if (is_full()) {
        cout << "Cannot add an element to full deq\n";
        return;
    }

    if (front == -1) { // Empty deque
        front = 0;
        rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }

    items[rear] = item;
}
// pop_front
int deq::pop_rear() {
    if (is_empty()) {
        cout << "Cannot delete an element from empty deq\n";
        return -1;
    }

    int item = items[rear];
    if (front == rear) { // Only one element was present
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear = rear - 1;
    }

    return item;
}
// pop_rear
int deq::pop_rear() {
    if (is_empty()) {
        cout << "Cannot delete an element from empty deq\n";
        return -1;
    }

    int item = items[rear];
    if (front == rear) { // Only one element was present
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear = rear - 1;
    }

    return item;
}