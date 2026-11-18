#include <iostream>
#include <vector>
using namespace std;

void kSmallest(vector<int> &arr, int k){
    int n = arr.size();
    for(int i = 0; i<k; i++){
        int minIdx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15, 1, 8};
    int k = 3;

    kSmallest(arr, k);

    for(int i = 0; i<k; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "kth smallest: " << arr[k-1] << endl;
    return 0;
}
