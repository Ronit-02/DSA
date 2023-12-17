#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;
}

void altSwap(int arr[], int n){

    for(int i=0; i<n; i+=2){

        if(i+1 < n)
            Swap(arr[i], arr[i+1]);
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    altSwap(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }

    return 0;
}