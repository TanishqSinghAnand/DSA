// Queue as ADT using an Array (circular queue)
#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX;  // wrap around to reuse empty space
        arr[rear] = value;
        count++;
        cout << value << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        front = (front + 1) % MAX;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // overflow
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(70);  // reuses the freed space
    q.display();

    return 0;
}
