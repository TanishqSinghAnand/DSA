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

int getMax(Node* head){
    int maxVal = head->data;
    for(Node* temp = head; temp != nullptr; temp = temp->next){
        if(temp->data > maxVal) maxVal = temp->data;
    }
    return maxVal;
}

Node* countSortByDigit(Node* head, int exp){
    Node* buckets[10] = {nullptr};
    Node* bucketTails[10] = {nullptr};

    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        int digit = (curr->data / exp) % 10;
        curr->next = nullptr;
        if(buckets[digit] == nullptr){
            buckets[digit] = curr;
            bucketTails[digit] = curr;
        } else {
            bucketTails[digit]->next = curr;
            bucketTails[digit] = curr;
        }
        curr = next;
    }

    Node* sorted = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i<10; i++){
        Node* b = buckets[i];
        while(b != nullptr){
            Node* next = b->next;
            if(sorted == nullptr){
                sorted = b;
                tail = b;
            } else {
                tail->next = b;
                tail = b;
            }
            tail->next = nullptr;
            b = next;
        }
    }
    return sorted;
}

Node* radixSort(Node* head){
    int maxVal = getMax(head);

    for(int exp = 1; maxVal/exp > 0; exp *= 10){
        head = countSortByDigit(head, exp);
    }
    return head;
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
    int arr[] = {170,45,75,90,802,24,2,66};
    for(int val : arr){
        head = insertAtEnd(head, val);
    }

    head = radixSort(head);

    printList(head);
    return 0;
}
