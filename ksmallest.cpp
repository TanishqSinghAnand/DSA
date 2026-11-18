// Find the K smallest elements of an array
// Idea: partially sort the array using selection sort for k passes.
// After k passes the first k positions hold the k smallest elements.
#include <iostream>
using namespace std;

void kSmallest(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    cout << "The " << k << " smallest elements are: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The " << k << "th smallest element is: " << arr[k - 1] << endl;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (k < 1 || k > n) {
        cout << "Invalid value of k" << endl;
        return 0;
    }

    kSmallest(arr, n, k);

    return 0;
}
