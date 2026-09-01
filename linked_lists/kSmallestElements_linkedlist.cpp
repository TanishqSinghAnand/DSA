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

Node* kSmallestElements(Node* head, int k){
    selectionSort(head);

    Node* result = nullptr;
    Node* curr = head;
    for(int i = 0; i<k && curr != nullptr; i++){
        result = insertAtEnd(result, curr->data);
        curr = curr->next;
    }
    return result;
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

    int k = 4;
    Node* result = kSmallestElements(head, k);

    printList(result);
    return 0;
}
