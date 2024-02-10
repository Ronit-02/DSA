#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator Function, controls how comparison is done in sorting algo
// Inbuilt Sort: O(n.logn)
bool compare(int a, int b){

    return a < b;  // ascending order
    // return a > b;  // descending order
}

int main() {

    int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // sort(arr, arr + n);
    // sort(arr, arr + n, greater<int>());
    sort(arr, arr + n, compare);

    for(int x : arr){
        cout<< x <<endl;
    }

    return 0;
}