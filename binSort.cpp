#include <iostream>
#include <vector>
using namespace std;

void binSort(vector<int> &arr){
    int maxVal = arr[0];
    for(int val : arr){
        if(val > maxVal) maxVal = val;
    }

    vector<int> bins(maxVal+1, 0);
    for(int val : arr){
        bins[val]++;
    }

    int idx = 0;
    for(int i = 0; i<=maxVal; i++){
        while(bins[i]-- > 0){
            arr[idx++] = i;
        }
    }
}

int main()
{
    vector<int> arr = {8,5,4,3,2,1,6,9,11};

    binSort(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
