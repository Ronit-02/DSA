#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        while(i >= 0 && j >= 0){
            
            if(arr1[i] >= arr2[j]){
                arr1[k] = arr1[i];
                i--;
            }
            else{
                arr1[k] = arr2[j];
                j--;
            } 
            k--;
        }
        while(j>=0){
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        
    }
};

int main(){

    Solution s;

    vector<int>arr1 = {4,5,6,0,0,0};
    int m = 3;

    vector<int>arr2 = {1,2,3};
    int n = 3;
    
    s.merge(arr1, m, arr2, n);

    for(int i=0; i<m+n; ++i)
        cout<<arr1[i]<<" ";

    return 0;
}