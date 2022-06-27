#include<iostream>

using namespace std;

bool binarySearch(int arr[], int s, int e, int key){

    int mid = s + (e-s)/2;

    // Base Case
    if(arr[mid] == key)   // element found
        return true;
    if(s > e)             // element not found
        return false;

    // Recursive Calls
    if(arr[mid] < key)
        return binarySearch(arr, s+1, e, key);
    else
        return binarySearch(arr, s, e-1, key);
}

int main(){

    int arr[5] = {1,1,2,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int key = 5;
    int start = 0;
    int end = size - 1;

    if(binarySearch(arr, start, end, key))
        cout << "Present";
    else
        cout << "Not present";

    return 0;
}