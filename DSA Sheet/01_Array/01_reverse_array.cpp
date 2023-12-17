#include<iostream>

using namespace std;

// Normal Approach
// TC: O(n)
void reverse1(int arr[], int n){

    int s = 0, e = n-1;
    
    while(s < e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        s++;
        e--;
    }
}

// Recursion Approach
// TC: O(n)
void reverse2(int arr[], int s, int e){

    if(s > e)
        return;

    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;

    reverse2(arr, s+1, e-1);
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    reverse1(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << endl;
    reverse2(arr, 0, n-1);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}