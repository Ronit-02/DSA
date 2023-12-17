#include<iostream>

using namespace std;

// Sorting
// TC: O(nlogn)
int kmin1(int arr[], int n, int k){

    return 0;
}

// QuickSelect
// TC: O(n^2) and O(n) avg
int partition(int arr[], int l, int r){

    int pivot = arr[l];
    int s = l;
    int e = r;
    while(s < e){

        while(arr[s] <= pivot) s++;
        while(arr[e] >= pivot) e--;

        if(s < e) 
            swap(arr[s], arr[e]);
    }
    swap(arr[e], arr[l]);
    return e;
}
int quickSelect(int arr[], int l, int r, int k){

    int pos = partition(arr, l, r);

    if(pos == k-1)
        return arr[pos];
    else if(pos > k-1)
        return quickSelect(arr, l, pos-1, k);
    else
        return quickSelect(arr, pos+1, r, k);
}
int kmin2(int arr[], int n, int k){

    return quickSelect(arr, 0, n-1, k);
}

// Max Heap
// TC: O()
int kmin3(int arr[], int n, int k){

    return 0;
}

int main(){

    int arr[] = {1,5,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 2;
    int ans = kmin2(arr, n, k);
    cout << ans;
    
    return 0;
}