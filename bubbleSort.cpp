#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> arr = {8,5,4,3,2,1,6,9,11};

    bubbleSort(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
