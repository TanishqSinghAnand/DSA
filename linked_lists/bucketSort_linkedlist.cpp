#include <iostream>
#include <vector>
using namespace std;

struct Node {
    float data;
    Node* next;
};

Node* newNode(float data){
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

Node* insertAtEnd(Node* head, float data){
    Node* node = newNode(data);
    if(head == nullptr) return node;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = node;
    return head;
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

Node* bucketSort(Node* head, int n){
    vector<Node*> buckets(n, nullptr);

    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        int idx = n * curr->data;
        curr->next = nullptr;
        buckets[idx] = sortedInsert(buckets[idx], curr);
        curr = next;
    }

    Node* sorted = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i<n; i++){
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
    float arr[] = {0.42f,0.32f,0.23f,0.52f,0.25f,0.47f,0.51f};
    for(float val : arr){
        head = insertAtEnd(head, val);
    }

    head = bucketSort(head, 7);

    printList(head);
    return 0;
}
