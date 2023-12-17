#include<iostream>
#include<utility>

using namespace std;

// Linear Search
// TC: O(n), SC: O(1)
pair<int,int> minmax(int arr[], int n){

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        if(maxi < arr[i]) maxi = arr[i];
        if(mini > arr[i]) mini = arr[i];
    }

    pair<int, int> p = {maxi, mini};
    return p;
}

int main(){

    int arr[] = {1,5,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    pair<int,int> p = minmax(arr, n);
    cout << p.first << " " << p.second;
    
    return 0;
}