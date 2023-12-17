#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator Function, controls how comparison is done in sorting algo
// Inbuilt Sort: O(n.logn)
bool compare(int a, int b){

    return a < b;
    // descending order: a > b
    // ascending order: a < b
}

int main() {

    int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // sort(arr, arr + n);
    // reverse(arr, arr + n);  
    // sort(arr, arr + n, greater<int>());     // inbuild comparator
    sort(arr, arr + n, compare);     // argument(start, end, comparator fn)

    for(int x : arr){
        cout<< x <<endl;
    }

    return 0;
}