#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float> &b){
    for(int i = 1; i<b.size(); i++){
        float key = b[i];
        int j = i-1;
        while(j >= 0 && b[j] > key){
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = key;
    }
}

void bucketSort(vector<float> &arr){
    int n = arr.size();
    vector<float> bucket[10];

    for(int i = 0; i<n; i++){
        int idx = arr[i] * 10;
        bucket[idx].push_back(arr[i]);
    }

    for(int i = 0; i<10; i++){
        insertionSort(bucket[i]);
    }

    int k = 0;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
}

int main()
{
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    bucketSort(arr);

    for(float val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
