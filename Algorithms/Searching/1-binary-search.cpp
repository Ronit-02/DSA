#include <iostream>
using namespace std;


// Iterative
int f1(int arr[], int n, int key){

    int start = 0, end = n-1;

    while(start <= end){

        int mid = (start + end)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    // if not present
    return -1;
}

// Recursion
bool f2(int arr[], int s, int e, int key){

    int mid = s + (e-s)/2;

    // Base Cases
    if(arr[mid] == key)   // element found
        return true;
    if(s > e)             // element not found
        return false;

    // Recursive Calls
    if(arr[mid] < key)
        return f2(arr, s+1, e, key);
    else
        return f2(arr, s, e-1, key);
}

int main() {

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;

    // cout << f1(arr, n, key);
    cout << f2(arr, 0, n-1, key);
    
    return 0;
}