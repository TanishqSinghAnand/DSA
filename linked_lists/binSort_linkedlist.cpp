#include <iostream>
#include <vector>
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

Node* binSort(Node* head, int maxVal){
    vector<Node*> bins(maxVal+1, nullptr);

    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        curr->next = bins[curr->data];
        bins[curr->data] = curr;
        curr = next;
    }

    Node* sorted = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i<=maxVal; i++){
        Node* b = bins[i];
        while(b != nullptr){
            if(sorted == nullptr){
                sorted = b;
                tail = b;
            } else {
                tail->next = b;
                tail = b;
            }
            b = b->next;
        }
    }
    if(tail != nullptr) tail->next = nullptr;
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
    for(int val : arr){
        head = insertAtEnd(head, val);
    }

    head = binSort(head, 11);

    printList(head);
    return 0;
}
