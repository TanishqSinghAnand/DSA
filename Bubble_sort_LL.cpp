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

void bubbleSort(Node* head){
    if(head == nullptr) return;

    bool swapped;
    Node* last = nullptr;

    do{
        swapped = false;
        Node* curr = head;
        while(curr->next != last){
            if(curr->data > curr->next->data){
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
        last = curr;
    }while(swapped);
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
    int arr[] = {5, 1, 4, 2, 8, 3};

    for(int i = 0; i<6; i++){
        head = insertAtEnd(head, arr[i]);
    }

    printList(head);
    bubbleSort(head);
    printList(head);

    return 0;
}
