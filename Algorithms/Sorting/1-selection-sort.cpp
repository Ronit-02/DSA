#include<iostream>
#include<vector>
using namespace std;

// Selection sort algorithm sorts an array by repeatedly finding the 
// minimum element from the unsorted part and putting it at the beginning.

// Iterative
void f1(vector<int> &arr, int n)
{   
    for(int i=0; i<n-1; ++i){
           
        int minIndex = i;
        for(int j=i+1; j<n; ++j){
            if(arr[minIndex] > arr[j]) 
                minIndex = j;
        }
        
        swap(arr[minIndex], arr[i]); 
    }
}

// Recursive
void f2(vector<int>& arr, int i){   
    
    // Base Case
    if(i == arr.size()-1)
        return;

    for(int j = i+1; j < arr.size(); j++){
        if(arr[j] < arr[i])
            swap(arr[i], arr[j]);
    }
    
    // Recursive Call
    f2(arr, i+1);   
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    // f1(arr, n);
    f2(arr, n);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}