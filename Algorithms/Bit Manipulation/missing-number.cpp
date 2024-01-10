#include<iostream>
using namespace std;

// Ques: 
// Given an array arr[] of size N-1 with integers in the range of [1, N], 
// the task is to find the missing number from the first N integers. (no duplicates) 

// Intuition: 
// using XOR operator property (a ^ a = 0)

int missing(int arr[], int n){

    int xor1 = arr[0];
    for(int i=1; i < n-1; i++){
        xor1 = xor1 ^ arr[i];
    }

    int xor2 = 1;
    for(int i=2; i<=n; i++){
        xor2 = xor2 ^ i;
    }

    return (xor1 ^ xor2);
}

int main(){

    int arr[] = {1,2,4,5};
    int n = 5;

    int ans = missing(arr, n);
    cout << ans;

    return 0;
}