// Bubble Sort on a Linked List
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

// compare neighbouring nodes and swap their data if out of order
void bubbleSort(Node* head) {
    if (head == NULL) {
        return;
    }
    bool swapped;
    Node* last = NULL;  // nodes after 'last' are already sorted

    do {
        swapped = false;
        Node* curr = head;
        while (curr->next != last) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}

int main() {
    Node* head = NULL;
    int values[] = {5, 1, 4, 2, 8, 3};
    int n = 6;

    for (int i = 0; i < n; i++) {
        insertAtEnd(head, values[i]);
    }

    cout << "Before sorting: ";
    display(head);

    bubbleSort(head);

    cout << "After sorting: ";
    display(head);

    return 0;
}
