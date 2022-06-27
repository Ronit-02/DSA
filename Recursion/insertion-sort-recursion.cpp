#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& arr, int i){   
    
    // Base Case
    if(i == arr.size())
        return;

    // Ek case solve krle, baaki recursion dekhlega
    int j = i-1;
    int val = arr[i];
    while(arr[j] > val && j>=0){ 
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = val;
    
    //Recursive Call
    insertionSort(arr, i+1);   
}
    
int main(){

    vector<int>arr = {5,4,3,2,1};
    
    insertionSort(arr, 1);
    
    for(int i=0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";

    return 0;
}



