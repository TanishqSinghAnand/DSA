#include <iostream>
using namespace std;

#define MAX 10

class List{
    int arr[MAX];
    int size;

public:
    List(){
        size = 0;
    }

    void insert(int pos, int val){
        if(size == MAX){
            cout << "list full" << endl;
            return;
        }
        if(pos < 0 || pos > size){
            cout << "invalid pos" << endl;
            return;
        }
        for(int i = size; i>pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
        size++;
    }

    void remove(int pos){
        if(size == 0){
            cout << "list empty" << endl;
            return;
        }
        if(pos < 0 || pos >= size){
            cout << "invalid pos" << endl;
            return;
        }
        for(int i = pos; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }

    int search(int val){
        for(int i = 0; i<size; i++){
            if(arr[i] == val) return i;
        }
        return -1;
    }

    int get(int pos){
        if(pos < 0 || pos >= size) return -1;
        return arr[pos];
    }

    int length(){
        return size;
    }

    void print(){
        for(int i = 0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    List l;

    l.insert(0, 10);
    l.insert(1, 20);
    l.insert(2, 30);
    l.insert(1, 15);
    l.print();

    cout << "length: " << l.length() << endl;
    cout << "get(2): " << l.get(2) << endl;
    cout << "search 30: " << l.search(30) << endl;

    l.remove(0);
    l.print();

    return 0;
}
