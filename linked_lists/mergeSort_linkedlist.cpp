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

Node* merge(Node* left, Node* right){
    if(left == nullptr) return right;
    if(right == nullptr) return left;

    if(left->data <= right->data){
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* getMiddle(Node* head){
    if(head == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* mid = getMiddle(head);
    Node* rightHalf = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHalf);

    return merge(left, right);
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

    head = mergeSort(head);

    printList(head);
    return 0;
}
