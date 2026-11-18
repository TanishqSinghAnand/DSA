// Fixed size List implemented using an Array (List as ADT)
#include <iostream>
using namespace std;

#define MAX 10

class FixedList {
    int arr[MAX];
    int size;

public:
    FixedList() {
        size = 0;
    }

    bool isFull() {
        return size == MAX;
    }

    bool isEmpty() {
        return size == 0;
    }

    // insert value at given position (0 based)
    void insert(int pos, int value) {
        if (isFull()) {
            cout << "List is full!" << endl;
            return;
        }
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        // shift elements to the right
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    // delete element at given position
    void remove(int pos) {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        // shift elements to the left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // returns index of value, or -1 if not found
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int get(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return -1;
        }
        return arr[pos];
    }

    int length() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    FixedList list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);
    cout << "List: ";
    list.display();

    cout << "Length: " << list.length() << endl;
    cout << "Element at position 2: " << list.get(2) << endl;
    cout << "Index of 30: " << list.search(30) << endl;

    list.remove(0);
    cout << "After deleting position 0: ";
    list.display();

    return 0;
}
