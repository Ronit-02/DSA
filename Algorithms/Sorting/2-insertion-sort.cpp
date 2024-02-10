#include<iostream>
#include<vector>
using namespace std;

// The array is split into a sorted and  unsorted part. 

// Values from the unsorted part are picked and placed at the 
// correct position in the sorted part.

// Iterative
void f1(vector<int> &arr, int n){
    
    for(int i=1; i<n; ++i){ 
    
        int val = arr[i]; 
        int j = i-1;     

        // insert val in sorted array
        while(arr[j] > val && j >= 0){    
            // go back till you reach an element 
            // which is smaller than element to be inserted    
            arr[j+1] = arr[j];
            j--;
        }
        // then insert it
        arr[j+1] = val;  
    }
}

// Recursion
void f2(vector<int>& arr, int i){   
    
    // base case
    if(i == arr.size())
        return;

    int j = i-1;
    int val = arr[i];

    while(arr[j] > val && j>=0){ 
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = val;
    
    // recursive call
    f2(arr, i+1);   
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    f1(arr, n);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}