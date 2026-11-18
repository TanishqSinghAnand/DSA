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

Node* insertionSort(Node* head){
    Node* sorted = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* next = curr->next;

        if(sorted == nullptr || curr->data < sorted->data){
            curr->next = sorted;
            sorted = curr;
        }
        else{
            Node* temp = sorted;
            while(temp->next != nullptr && temp->next->data < curr->data){
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
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
    int arr[] = {12, 11, 13, 5, 6, 1};

    for(int i = 0; i<6; i++){
        head = insertAtEnd(head, arr[i]);
    }

    printList(head);
    head = insertionSort(head);
    printList(head);

    return 0;
}
