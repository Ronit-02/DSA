#include<iostream>

using namespace std;

bool linearSearch(int arr[], int size, int key){

    // Base Case
    if(size == 0)
        return false;
    // ek cheez krleta hun, baaki recursion krlega
    if(arr[0] == key)
        return true;
    // Recursive Call
    return linearSearch(arr+1, size-1, key);
}

int main(){

    int arr[5] = {1,1,2,4,6};
    
    int key = 2;
    int size = sizeof(arr)/sizeof(arr[0]);

    if(linearSearch(arr, size, key))
        cout << "Present";
    else
        cout << "Not present";

    return 0;
}