#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue{
    Node* front;
    Node* rear;

public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int data){
        Node* node = new Node();
        node->data = data;
        node->next = nullptr;

        if(rear == nullptr){
            front = rear = node;
            return;
        }
        rear->next = node;
        rear = node;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek(){
        if(isEmpty()) return -1;
        return front->data;
    }

    void print(){
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
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
    q.print();

    cout << "front: " << q.peek() << endl;

    q.dequeue();
    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
