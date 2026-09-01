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

bool alreadySeen(Node* seen, int val){
    while(seen != nullptr){
        if(seen->data == val) return true;
        seen = seen->next;
    }
    return false;
}

Node* findDuplicate(Node* head){
    Node* seen = nullptr;
    Node* duplicates = nullptr;

    Node* temp = head;
    while(temp != nullptr){
        if(alreadySeen(seen, temp->data)){
            duplicates = insertAtEnd(duplicates, temp->data);
        } else {
            seen = insertAtEnd(seen, temp->data);
        }
        temp = temp->next;
    }
    return duplicates;
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
    int arr[] = {8,5,4,3,2,1,6,9,5,4,11};
    for(int val : arr){
        head = insertAtEnd(head, val);
    }

    Node* duplicates = findDuplicate(head);

    printList(duplicates);
    return 0;
}
