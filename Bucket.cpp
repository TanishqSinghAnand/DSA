#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<float> &arr){
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for(int i = 0; i<n; i++){
        int idx = n * arr[i];
        buckets[idx].push_back(arr[i]);
    }

    for(int i = 0; i<n; i++){
        for(int j = 1; j<buckets[i].size(); j++){
            float key = buckets[i][j];
            int k = j-1;
            while(k>=0 && buckets[i][k] > key){
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    int idx = 0;
    for(int i = 0; i<n; i++){
        for(float val : buckets[i]){
            arr[idx++] = val;
        }
    }
}

int main()
{
    vector<float> arr = {0.42f,0.32f,0.23f,0.52f,0.25f,0.47f,0.51f};

    bucketSort(arr);

    for(float val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
