#include<iostream>
#include<vector>

using namespace std;

// T(n) = T(n/2) + O(n);    T(n/2) -> recursive calls, O(n) -> merging
// Time Complexity : O(n log(n))   
    
void merge(vector<int> &arr, int start, int mid, int end){

    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<int> arr1(len1);
    vector<int> arr2(len2);

    int i, j, k = start;   // indexes for 3 arrays

    for(i = 0; i < len1; i++, k++)
        arr1[i] = arr[k];

    for(j = 0; j < len2; j++, k++)
        arr2[j] = arr[k];


    k = start;   // index of merged array
    i = 0;
    j = 0;

    while(i < len1 && j < len2){
        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while(i < len1)
        arr[k++] = arr1[i++];

    while(j < len2)
        arr[k++] = arr2[j++];
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



