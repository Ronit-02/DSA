#include <iostream>
#include <vector>
using namespace std;

// Definition:
// Cyclic Sort only works when no's are given in a cts range(1, n)

// Intuition: 
// Ignore all the elements that are negative or greater than array size
// Time Complexity: O(n)
void cyclicSort(vector<int> &arr){

    // Method: check, swap, move
    int i=0;
    while(i < arr.size()){
        int posn = arr[i]-1;   // no's are 1..n
        if(arr[i] != arr[posn])
            swap(arr[i], arr[posn]);
        else
            i++;
    }
}

int main() {

    vector<int> arr = {4,5,2,3,1};

    cyclicSort(arr);

    for(int x : arr){
        cout<< x <<endl;
    }

    return 0;
}