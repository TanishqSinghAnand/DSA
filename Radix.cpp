#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr, int place){
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for(int i = 0; i<n; i++){
        count[(arr[i]/place) % 10]++;
    }
    for(int i = 1; i<10; i++){
        count[i] += count[i-1];
    }
    for(int i = n-1; i>=0; i--){
        int d = (arr[i]/place) % 10;
        output[count[d]-1] = arr[i];
        count[d]--;
    }
    for(int i = 0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr){
    int maxVal = arr[0];
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    for(int place = 1; maxVal/place > 0; place *= 10){
        countSort(arr, place);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
