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

void bubbleSort(Node* head){
    if(head == nullptr) return;

    bool swapped = true;
    while(swapped){
        swapped = false;
        Node* curr = head;
        while(curr->next != nullptr){
            if(curr->data > curr->next->data){
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
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
    int arr[] = {8,5,4,3,2,1,6,9,11};
    for(int val : arr){
        head = insertAtEnd(head, val);
    }

    bubbleSort(head);

    printList(head);
    return 0;
}
