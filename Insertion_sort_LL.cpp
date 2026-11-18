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

Node* sortedInsert(Node* sorted, Node* node){
    if(sorted == nullptr || sorted->data >= node->data){
        node->next = sorted;
        return node;
    }

    Node* curr = sorted;
    while(curr->next != nullptr && curr->next->data < node->data){
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return sorted;
}

Node* insertionSort(Node* head){
    Node* sorted = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* next = curr->next;
        sorted = sortedInsert(sorted, curr);
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
    int arr[] = {8,5,4,3,2,1,6,9,11};
    for(int i = 8; i>=0; i--){
        Node* node = newNode(arr[i]);
        node->next = head;
        head = node;
    }

    head = insertionSort(head);

    printList(head);
    return 0;
}
