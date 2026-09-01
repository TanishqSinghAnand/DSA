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

Node* getTail(Node* head){
    while(head != nullptr && head->next != nullptr){
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd){
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;

    while(curr != pivot){
        if(curr->data < pivot->data){
            if(*newHead == nullptr) *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if(prev != nullptr) prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if(*newHead == nullptr) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRec(Node* head, Node* end){
    if(head == nullptr || head == end) return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if(newHead != pivot){
        Node* temp = newHead;
        while(temp->next != pivot){
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRec(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

Node* quickSort(Node* head){
    return quickSortRec(head, getTail(head));
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

    head = quickSort(head);

    printList(head);
    return 0;
}
