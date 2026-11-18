// Bucket Sort
// Elements are spread into buckets based on their value,
// each bucket is sorted, and then the buckets are joined together.
#include <iostream>
#include <vector>
using namespace std;

// simple insertion sort used to sort each bucket
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < (int)bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// works for values in the range [0, 1)
void bucketSort(float arr[], int n) {
    vector<float> buckets[10];  // 10 buckets

    // put each element into a bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] * 10;  // 0.42 goes to bucket 4
        buckets[index].push_back(arr[i]);
    }

    // sort every bucket
    for (int i = 0; i < 10; i++) {
        insertionSort(buckets[i]);
    }

    // join all buckets back into the array
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (int)buckets[i].size(); j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

void display(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    display(arr, n);

    bucketSort(arr, n);

    cout << "After sorting: ";
    display(arr, n);

    return 0;
}
