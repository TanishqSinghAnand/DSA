// Singly Linked List as ADT
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
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

    // insert at position (0 based)
    void insertAtPosition(int pos, int value) {
        if (pos == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << value << " not found!" << endl;
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtPosition(2, 15);
    cout << "List: ";
    list.display();

    cout << "Length: " << list.length() << endl;
    cout << "Is 20 present? " << (list.search(20) ? "Yes" : "No") << endl;

    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
