#include <iostream>
#include <algorithm>

using namespace std;

//Comparitor Function = controls how comparison is done in sorting algo
bool compare(int a, int b){
    return a > b;
    //reverse order (a > b)
    //ascending order (a < b)
}

int main() {

    int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    //Inbuild Sort  <-  O(n.logn)
    sort(arr, arr + n, compare);     //argument(start, end, comparitor fn)
    sort(arr, arr + n, greater<int>());     //inbuild comparitor

    // reverse(arr, arr + n);

    for(int x : arr){
        cout<< x <<endl;
    }

        return 0;
}