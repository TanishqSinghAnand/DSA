#include <iostream>
#include <vector>
using namespace std;

void moveZeroesToEnd(vector<int> &arr){
    int j = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {8,0,4,0,2,1,0,9,11};

    moveZeroesToEnd(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
