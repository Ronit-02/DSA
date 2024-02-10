#include<iostream>
#include<vector>
using namespace std;

// Bubble sort works by repeatedly swapping adjacent elements
// Time Complexity: O(n^2)

// Iterative
void f1(vector<int>& arr, int n)
{
    // (n-1) passes
    for(int i=0; i<n-1; i++){     
        bool swapped = false;

        // (n-i-1) passes
        for(int j=0; j<n-i-1; ++j){    
            
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // no swapping, already sorted
        if(swapped == false) 
            break;
    }
}

// Recursive
void f2(vector<int>& arr, int n){   
    
    // base Case
    if(n == 1)
        return;

    // n-1 passes
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    // recursive call
    f2(arr, n-1);   
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    // f1(arr, n);
    f2(arr, n);

    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";

    return 0;
}