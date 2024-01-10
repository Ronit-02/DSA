#include<iostream>
#include<vector>
using namespace std;

// Bubble sort works by repeatedly swapping adjacent elements
// Time Complexity: O(n^2)
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=0; i<n-1; ++i){     // (n-1) passes
    
        bool swapped = false;
        for(int j=0; j<n-i-1; ++j){   // (n-i-1) passes 
            
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)   // if no swapping occured -> already sorted
            break;
    }
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    bubbleSort(arr, n);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}