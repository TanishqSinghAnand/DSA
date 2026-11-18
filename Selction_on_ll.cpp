#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtEnd(Node* head, int data){
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    if(head == nullptr) return node;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

void selectionSort(Node* head){
    for(Node* i = head; i != nullptr; i = i->next){
        Node* minNode = i;
        for(Node* j = i->next; j != nullptr; j = j->next){
            if(j->data < minNode->data){
                minNode = j;
            }
        }
        int temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
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
    int arr[] = {64, 25, 12, 22, 11, 90};

    for(int i = 0; i<6; i++){
        head = insertAtEnd(head, arr[i]);
    }

    printList(head);
    selectionSort(head);
    printList(head);

    return 0;
}
