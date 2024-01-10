#include<iostream>
#include<vector>

using namespace std;

// Time Complexity: O(n^2)
// Traverse array, for every index, find no of smaller elements on its right side
// Sum of the counts of all indexes is answer
int countInversionBF(vector<int> arr, int n){

    int count = 0;
    for(int i=0; i<n-1; i++){     
        for(int j=i+1; j<n; j++)
            if(arr[i] > arr[j])
                count++;
    }
    return count;
} 

int merge(vector<int> &arr,  vector<int> temp, int l, int mid, int r){

    int invCount = 0;
    int i = l;    // index for left subarray
    int j = mid;  // index for right subarray
    int k = l;    // index for merge sorted array

    while(i <= mid-1 && j <= r){

        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else{
            temp[k++] = arr[j++];
            invCount += (mid-i);
        }
    }
    // copy remaining elements
    while(i <= mid-1)
        temp[k++] = arr[i++];        

    while(j <= r)
        temp[k++] = arr[j++];        

    for(int i=l; i <= r; i++)
        arr[i] = temp[i];

    return invCount;

}
int mergeSort(vector<int> &arr, int l, int r){

    int invCount = 0;
    int mid = 0;
    vector<int> temp(r-l+1);

    if(l < r){   // when 1 element remaining
     
        mid = l+(r-l)/2;
        
        invCount += mergeSort(arr, l, mid);
        invCount += mergeSort(arr, mid+1, r);
        invCount += merge(arr, temp , l, mid, r);
    }

    return invCount;
}

// Time Complexity: O(n log(n))
// Total no of inversions = inversions in the left subarray + right subarray + merge()
// Inversions in merge -> (mid-i) inversions, when a[i] > a[j] 
int countInversion(vector<int> arr, int n){

    int ans = mergeSort(arr, 0, n-1);
    return ans;
}

int main(){ 

    vector<int> arr = {2,5,3,1,4};

    int output = countInversion(arr, arr.size());
    cout << output << endl;

    return 0;
}