#include <iostream>
using namespace std;

#define MAX 5

class Queue{
    int arr[MAX];
    int front, rear, count;

public:
    Queue(){
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == MAX;
    }

    void enqueue(int val){
        if(isFull()){
            cout << "overflow" << endl;
            return;
        }
        rear = (rear+1) % MAX;
        arr[rear] = val;
        count++;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        front = (front+1) % MAX;
        count--;
    }

    int peek(){
        if(isEmpty()) return -1;
        return arr[front];
    }

    void print(){
        for(int i = 0; i<count; i++){
            cout << arr[(front+i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print();

    cout << "front: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.print();

    q.enqueue(70);
    q.print();

    return 0;
}
