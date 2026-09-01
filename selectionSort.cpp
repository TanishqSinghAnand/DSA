#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
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
    vector<int> arr = {8,5,4,3,2,1,6,9,11};

    selectionSort(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
