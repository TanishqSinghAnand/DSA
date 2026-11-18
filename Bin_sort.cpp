// Bin Sort (also called Counting Sort for small integer ranges)
// Each possible value gets its own "bin". We count how many times
// each value occurs and then write the values back in order.
#include <iostream>
using namespace std;

void binSort(int arr[], int n) {
    // find the largest value to know how many bins we need
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // create bins and set all counts to 0
    int* bins = new int[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        bins[i] = 0;
    }

    // put each element in its bin
    for (int i = 0; i < n; i++) {
        bins[arr[i]]++;
    }

    // collect elements back from the bins
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (bins[i] > 0) {
            arr[index] = i;
            index++;
            bins[i]--;
        }
    }

    delete[] bins;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 7, 1, 3, 2, 9, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    display(arr, n);

    binSort(arr, n);

    cout << "After sorting: ";
    display(arr, n);

    return 0;
}
