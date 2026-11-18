#include <iostream>
using namespace std;

#define MAX 5

class Stack{
    int arr[MAX];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == MAX-1;
    }

    void push(int val){
        if(isFull()){
            cout << "overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop(){
        if(isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        top--;
    }

    int peek(){
        if(isEmpty()) return -1;
        return arr[top];
    }

    void print(){
        for(int i = top; i>=0; i--){
            cout << arr[i] << " ";
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
    s.push(40);
    s.push(50);
    s.push(60);
    s.print();

    cout << "top: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.print();

    return 0;
}
