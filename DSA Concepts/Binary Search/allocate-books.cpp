#include<iostream>
#include<vector>
using namespace std;

// Function to check if we can allocate 'mid'  
// no of pages among 'm' students
bool canAllocate(vector<int> &arr, int n, int m, int mid){
    
    int studentCount = 1;
    int sum = 0;                   // represents total pages
    for(int i=0; i<n; ++i){
        if(sum + arr[i] <= mid){   // if we can assign same book to that student
            sum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid)  // can't allot more !!
                return false;
            sum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    
    int tpages = 0; 
    for(int i=0; i<n; ++i){
        tpages += arr[i];
    }
    
    int ans = -1;
    int s = 0;
    int e = tpages;             // binary search from 0 -> tpages
    int mid = s + (e-s)/2;
    while(s <= e){
        if(canAllocate(arr, n, m, mid)){  // if 'mid' pages possible tp allocate
            ans = mid;
            e = mid-1;          // if yes, check for less pages
        }
        else{
            s = mid+1;         // if no, check for more pages
        }
        mid = s + (e-s)/2;
    }
    
    return ans;
}

int main(){

    return 0;
}