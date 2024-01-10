#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n){   
    
    // Base Case
    if(n == 1)
        return;

    // Ek case solve krle, baaki recursion dekhlega
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    //Recursive Call
    bubbleSort(arr, n-1);   
}
    
int main(){

    vector<int>arr = {2,5,1,4,3};
    
    bubbleSort(arr, arr.size());

    for(int i=0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";

    return 0;
}



