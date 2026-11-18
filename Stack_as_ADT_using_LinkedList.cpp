#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack{
    Node* top;

public:
    Stack(){
        top = nullptr;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    void push(int data){
        Node* node = new Node();
        node->data = data;
        node->next = top;
        top = node;
    }

    void pop(){
        if(isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(isEmpty()) return -1;
        return top->data;
    }

    void print(){
        Node* temp = top;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.print();

    cout << "top: " << s.peek() << endl;

    s.pop();
    s.print();

    s.pop();
    s.pop();
    s.pop();

    return 0;
}
