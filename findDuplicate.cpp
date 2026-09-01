#include <iostream>
#include <vector>
using namespace std;

bool alreadySeen(vector<int> &seen, int val){
    for(int v : seen){
        if(v == val) return true;
    }
    return false;
}

vector<int> findDuplicate(vector<int> &arr){
    vector<int> seen;
    vector<int> duplicates;

    for(int val : arr){
        if(alreadySeen(seen, val)){
            duplicates.push_back(val);
        } else {
            seen.push_back(val);
        }
    }
    return duplicates;
}

int main()
{
    vector<int> arr = {8,5,4,3,2,1,6,9,5,4,11};

    vector<int> duplicates = findDuplicate(arr);

    for(int val : duplicates){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
