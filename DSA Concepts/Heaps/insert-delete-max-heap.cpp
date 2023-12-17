#include<iostream>
using namespace std;


class heap {
public:

    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 1;
    }

    // TC: O(log n)
    void insert(int x){

        // 1. insertion at leaf node
        int index = size;
        arr[index] = x;
        size++;

        // 2. heapify the last node (bottom-up)
        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    // TC: O(log n)
    void deleteFromHeap(){

        // 1. put root element at leaf node
        arr[1] = arr[size-1];

        // 2. removing last element
        size--;

        // 3. heapify the root node (top-down)
        int i = 1;
        while(i < size){

            int left = 2*i;
            int right = 2*i + 1;

            if(left < size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }
            else
                return;
        } 
    }

    void print(){

        for(int i=1; i<size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main(){

    heap h;
    h.insert(1);
    h.insert(5);
    h.insert(0);
    h.print();

    h.deleteFromHeap();
    h.print();

    return 0;
}