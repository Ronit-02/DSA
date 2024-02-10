#include<iostream>

using namespace std;

int sum(int i, int arr[]){

    // Base Case
    if(i == 0)
        return arr[0];

    // Recursive Call
    return arr[i] + sum(i-1, arr);
}

int main(){

    int arr[5] = {1,1,2,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << sum(size-1, arr);

    return 0;
}