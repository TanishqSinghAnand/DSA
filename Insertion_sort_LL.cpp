// Insertion Sort on a Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// take nodes one by one from the original list
// and insert them at the correct place in a new sorted list
Node* insertionSort(Node* head) {
    Node* sorted = NULL;

    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;

        if (sorted == NULL || curr->data < sorted->data) {
            // insert at beginning of sorted list
            curr->next = sorted;
            sorted = curr;
        } else {
            // find the correct spot
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = nextNode;
    }
    return sorted;
}

int main() {
    Node* head = NULL;
    int values[] = {12, 11, 13, 5, 6, 1};
    int n = 6;

    for (int i = 0; i < n; i++) {
        insertAtEnd(head, values[i]);
    }

    cout << "Before sorting: ";
    display(head);

    head = insertionSort(head);

    cout << "After sorting: ";
    display(head);

    return 0;
}
