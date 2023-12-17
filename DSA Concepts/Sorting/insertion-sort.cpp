#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    
    int i, j, val;
    for(i=1; i<n; ++i){    // (n-1) passes required
    
        j = i-1;     
        val = arr[i];       // val to be inserted in sorted array

        while(arr[j] > val && j>=0){    
            // go back till you reach an element 
            // which is smaller than element to be inserted    
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;  // then insert it
    }
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    insertionSort(arr, n);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}