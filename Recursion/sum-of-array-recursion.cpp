#include<iostream>

using namespace std;

int sum(int arr[], int size){

    // Base Case
    if(size == 1)
        return arr[0];

    // Recursive Call
    int ans = arr[0] + sum(arr + 1, size - 1);
    return ans;
}

int main(){

    int arr[5] = {1,1,2,4,6};
    
    int output = sum(arr, 5);
    cout << output << endl;

    return 0;
}