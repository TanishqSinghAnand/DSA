// Radix Sort
// Sort numbers digit by digit, starting from the ones place,
// using counting sort for each digit.
#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// counting sort based on the digit at 'place' (1, 10, 100, ...)
void countingSort(int arr[], int n, int place) {
    int* output = new int[n];
    int count[10] = {0};

    // count how many numbers have each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // change count[i] so it holds the final position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // build output array (go backwards to keep it stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int place = 1; maxVal / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    display(arr, n);

    radixSort(arr, n);

    cout << "After sorting: ";
    display(arr, n);

    return 0;
}
