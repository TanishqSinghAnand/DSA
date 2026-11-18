// Selection Sort on a Linked List
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

// find the smallest node in the rest of the list and swap data
void selectionSort(Node* head) {
    for (Node* i = head; i != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }
        int temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
    }
}

int main() {
    Node* head = NULL;
    int values[] = {64, 25, 12, 22, 11, 90};
    int n = 6;

    for (int i = 0; i < n; i++) {
        insertAtEnd(head, values[i]);
    }

    cout << "Before sorting: ";
    display(head);

    selectionSort(head);

    cout << "After sorting: ";
    display(head);

    return 0;
}
