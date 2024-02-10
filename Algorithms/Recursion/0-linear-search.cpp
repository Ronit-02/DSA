#include<iostream>

using namespace std;

bool linearSearch(int i, int &key, int arr[]){

    // Base Case
    if(i < 0)
        return false;
    
    // Check
    if(arr[i] == key)
        return true;
    
    // Recursive Call
    return linearSearch(i-1, key, arr);
}

int main(){

    int arr[5] = {1,1,2,4,6};
    
    int key = 2;
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << linearSearch(size, key, arr);

    return 0;
}