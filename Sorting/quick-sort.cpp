#include<iostream>

using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[e];

    int i = s;  // tracking smaller numbers
    int j = s;  // tracking array elements
    
    // bring all the elements smaller than or equal to pivot before i
    while(j <= e){

        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
            j++;
    }
    return (i-1);   // as i-1 is where pivot is placed
}

void quickSort(int arr[], int s, int e){

    // base case
    if(s >= e)
        return;

    int pi = partition(arr, s, e);   // pi represent pivot index
    
    quickSort(arr, s, pi-1);  // left Subarray
    
    quickSort(arr, pi+1, e);  // Right Subarray
}

int main(){

    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}