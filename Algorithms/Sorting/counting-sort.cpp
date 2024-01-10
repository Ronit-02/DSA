#include <iostream>
#include <vector>
using namespace std;

//Counting sort is a sorting technique based on keys between a specific range.
//Time Complexity: O(n+k)
void countingSort(int arr[], int n){

    int largest = -1;

    //finding the largest element (determines the last index of count array)
    for(int i=0; i<n; i++){
        largest = max(largest, arr[i]);
    }

    vector<int> count(largest + 1, 0);

    //Update count array
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    //putting back elements in array
    int j=0;    //for original array
    for(int i=0; i<=largest; i++){   //for count array

        if(count[i]>0){
            arr[j] = i;
            count[i]--;
            j++;
        }
    }
}

int main() {

    int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    for(int x : arr){
        cout<< x <<endl;
    }

        return 0;
}