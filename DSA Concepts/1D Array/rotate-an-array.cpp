#include<iostream>
#include<vector>
using namespace std;

// Question:
// rotate an array to the right by 'k' times (clock-wise)

// using temp array / O(n) O(n)
void rotate1(vector<int> &arr , int k){
    
    int n = arr.size();
    k = k % n;
    vector<int> temp(n);
    
    // 1. store elements (n-k) to (n-1)
    int j = 0;
    for(int i=n-k; i<n; i++){
        temp[j] = arr[i];
        j++;
    }
    // 2. store elements 0 to (n-k)
    for(int i=0; i<n-k; i++){
        temp[j] = arr[i];
        j++;
    }

    arr = temp;
}

// rotating one by one / O(n*k)
void rotate2(vector<int> &arr , int k){
    
    int n = arr.size();
    k = k % n;

    for(int i=0; i<k; i++){

        int x = arr[n-1];
        for(int i=n-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = x;
    }
}

void reverse(vector<int> &arr , int s, int e){
    
    int n = arr.size();
    
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

// space optimization / O(n)
void rotate3(vector<int> &arr , int k){
    
    int n = arr.size();
    k = k % n;    

    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-1);
}

int main(){

    vector<int>arr = {1,2,3,4,5};
    rotate3(arr, 2);

    for(auto it: arr)
        cout << it;

    return 0;
}