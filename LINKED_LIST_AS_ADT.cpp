#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtStart(int data){
        Node* node = new Node();
        node->data = data;
        node->next = head;
        head = node;
    }

    void insertAtEnd(int data){
        Node* node = new Node();
        node->data = data;
        node->next = nullptr;

        if(head == nullptr){
            head = node;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
    }

    void insertAtPos(int pos, int data){
        if(pos == 0){
            insertAtStart(data);
            return;
        }
        Node* temp = head;
        for(int i = 0; i<pos-1 && temp != nullptr; i++){
            temp = temp->next;
        }
        if(temp == nullptr){
            cout << "invalid pos" << endl;
            return;
        }
        Node* node = new Node();
        node->data = data;
        node->next = temp->next;
        temp->next = node;
    }

    void deleteVal(int val){
        if(head == nullptr) return;

        if(head->data == val){
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val){
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout << "not found" << endl;
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    bool search(int val){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    int length(){
        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList l;

    l.insertAtEnd(10);
    l.insertAtEnd(20);
    l.insertAtEnd(30);
    l.insertAtStart(5);
    l.insertAtPos(2, 15);
    l.print();

    cout << "length: " << l.length() << endl;
    cout << "search 20: " << l.search(20) << endl;

    l.deleteVal(20);
    l.print();

    return 0;
}
