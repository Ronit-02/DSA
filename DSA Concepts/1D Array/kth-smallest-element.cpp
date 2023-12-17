#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        
        int ans = quickSelect(arr, l, r, k-1);   // answer lies in (k-1) index
        return ans;
    }
    int quickSelect(int arr[], int l, int r, int k){
     
        int pivot = arr[r];
        int pi = partition(arr, l, r, pivot); // partition returns correct index of pivot element
        
        if(pi == k)          // if index is equal -> pivot element is your answer
            return pivot;
        else if(pi > k)     // otherwise apply binary search
            return quickSelect(arr, l, pi-1, k);
        else
            return quickSelect(arr, pi+1, r, k);   
    }
    int partition(int arr[], int l, int r, int pivot){
        
        int i = l;
        int j = l;
        while(i <= r){
            
            if(arr[i] <= pivot){       // if smaller -> swap
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else                       // if larger -> dont swap
                i++;
        }
        return (j-1);
    }
};
    
int main(){

    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    
    Solution s;
    int output  = s.kthSmallest(arr, 0, n-1, k);
    
    cout << output << endl;

    return 0;
}



