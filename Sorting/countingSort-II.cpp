//Counting Sort using Comparitor

#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b){
    return a < b;
}

void countingSort(int arr[], int n){

    int largest = -1;
    for(int i=0; i<n; i++){
        largest = max(largest, arr[i]);
    }

    vector<int> count(largest+1, 0);

    int j=0;
    // for(int i=0; i<n; i++){
    //     if(compare)
    // }
}

int main(){

    int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    for(int x : arr){
        cout<< x <<endl;
    }

    return 0;
}