#include <iostream>
#include <vector>
using namespace std;

void binSort(vector<int> &arr){
    int n = arr.size();
    int maxVal = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    vector<int> bin(maxVal+1, 0);
    for(int i = 0; i<n; i++){
        bin[arr[i]]++;
    }

    int idx = 0;
    for(int i = 0; i<=maxVal; i++){
        while(bin[i] > 0){
            arr[idx++] = i;
            bin[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 7, 1, 3, 2, 9, 0, 4};

    binSort(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
