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

Node* insertAtBeginning(Node* head, int data){
    Node* node = newNode(data);
    node->next = head;
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

Node* deleteValue(Node* head, int val){
    if(head == nullptr) return head;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    while(curr->next != nullptr && curr->next->data != val){
        curr = curr->next;
    }

    if(curr->next != nullptr){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    return head;
}

bool search(Node* head, int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int lengthOfList(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
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

    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 4);
    head = insertAtBeginning(head, 11);

    cout << "List: ";
    printList(head);

    cout << "Length: " << lengthOfList(head) << endl;
    cout << "Search 5: " << (search(head, 5) ? "found" : "not found") << endl;

    head = deleteValue(head, 4);
    cout << "After deleting 4: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed: ";
    printList(head);

    return 0;
}
