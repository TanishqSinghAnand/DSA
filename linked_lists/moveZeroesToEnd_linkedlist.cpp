#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

Node* insertAtEnd(Node* head, int data){
    Node* node = newNode(data);
    if(head == nullptr) return node;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

void moveZeroesToEnd(Node* head){
    Node* lastNonZero = head;

    for(Node* curr = head; curr != nullptr; curr = curr->next){
        if(curr->data != 0){
            int temp = curr->data;
            curr->data = lastNonZero->data;
            lastNonZero->data = temp;
            lastNonZero = lastNonZero->next;
        }
    }
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int arr[] = {8,0,4,0,2,1,0,9,11};
    for(int val : arr){
        head = insertAtEnd(head, val);
    }

    moveZeroesToEnd(head);

    printList(head);
    return 0;
}
