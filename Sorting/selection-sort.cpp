#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0; i<n-1; ++i){     // (n-1) passes required for length n array
           
        int minIndex = i;         // initialy i is smallest value
        for(int j=i+1; j<n; ++j){
            if(arr[minIndex] > arr[j])    // comparing every value for smallest
                minIndex = j;
        }
        
        swap(arr[minIndex], arr[i]);    // swaping with smallest value
    }
}

int main(){

    vector<int>arr = {2,5,1,4,3};
    int n = 5;
    
    selectionSort(arr, n);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}