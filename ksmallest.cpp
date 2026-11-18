#include <iostream>
#include <vector>
using namespace std;

vector<int> kSmallestElements(vector<int> arr, int k){
    for(int i = 0; i<arr.size()-1; i++){
        int minIdx = i;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    return vector<int>(arr.begin(), arr.begin()+k);
}

int main()
{
    vector<int> arr = {8,5,4,3,2,1,6,9,11};
    int k = 4;

    vector<int> result = kSmallestElements(arr, k);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
