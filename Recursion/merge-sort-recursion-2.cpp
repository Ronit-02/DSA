#include<iostream>
#include<vector>

using namespace std;
    
void merge(vector<int> &arr, int start, int mid, int end){

    int len = end - start + 1;
    vector<int> temp(len);

    int i = start;
    int j = mid+1;
}

void mergeSort(vector<int> &arr, int start, int end){   
    
    // Base Case  
    if(start >= end)  // when single element is sorted
        return;

    int mid = start + (end - start)/2;

    // Left part 
    mergeSort(arr, start, mid);

    // Right part
    mergeSort(arr, mid+1, end);

    // Merging both parts
    merge(arr, start, mid, end);
}

int main(){

    vector<int>arr = {5,4,3,2,1};
    int n = arr.size();
    
    mergeSort(arr, 0, n-1);
    
    for(int i=0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";

    return 0;
}