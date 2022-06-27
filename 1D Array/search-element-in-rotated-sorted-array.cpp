#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int binSearch(vector<int>& arr, int target, int s, int e){
        
            int mid = s + (e-s)/2;
            
            while(s < e){
                if(arr[mid] == target)
                    return mid;
                else if(arr[mid] > target)
                    e = mid - 1;
                else
                    s = mid + 1;
                
                mid = s + (e-s)/2;
            }
        return -1;
    }
    
    int search(vector<int>& arr, int target) {
  
        int n = arr.size();   
        
        //find the pivot element
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int pivot = 0;
        
        while(s<e){
            if(arr[mid] > arr[0])  // lying in first line
                s = mid + 1;
            else
                e = mid;
        }
        pivot = s;
        
        //binary search for target wrt pivot
        if(target > arr[pivot]){ // second sorted part
            
            binSearch(arr, target, pivot, n-1);
        }
        else{   //first sorted part
            
            binSearch(arr, target, 0, pivot);
        }
        return -1;
    }

    int findPivot(vector<int>& arr){

        // cout<<"on it!";
        int n = arr.size();   
        
        //find the pivot element
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int pivot = 0;
        
        while(s < e){

            if(arr[mid] > arr[0])  // lying in first line
                s = mid + 1;
            else
                e = mid;

            mid = s + (e-s)/2;
        }
        return s;
    }
};

int main(){

    Solution s;

    vector<int> arr = {4,5,6,7,0,1,2};

    int output = s.findPivot(arr);
    // cout<<"Pivot element index is "<<output;
     
    return 0;
}