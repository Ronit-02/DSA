#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int partition(long long a[], int lo, int hi, int pivot){
        
        long long i = lo;
        long long j = lo;
        while(i <= hi){
            
            if(a[i] <= pivot){       // if smaller or equal -> swap
                swap(a[i], a[j]);
                i++;
                j++;
            }
            else                       // if larger -> dont swap
                i++;
        }
        return (j-1);      // correct position of pivot element
    }
    int quickSelect(long long a[], long long lo, long long hi, long long k){
     
        long long pivot = a[hi];
        long long pi = partition(a, lo, hi, pivot); 
        
        if(pi == k)         
            return pivot;
        else if(pi > k)   
            return quickSelect(a, lo, pi-1, k);
        else
            return quickSelect(a, pi+1, hi, k);
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
     
        int n1 = quickSelect(A, 0, N-1, K1-1);
        int n2 = quickSelect(A, 0, N-1, K2-1);

        cout << "First no is: " << n1 << endl;
        cout << "second no is: " << n2 << endl;
        
        long long i = 0;
        long long sum = 0;
        
        while(i < N){
            
            if(A[i] == n1){
                
                i++;
                while(A[i] != n2){
                    sum += A[i];
                    i++;
                }
                break;
            }
            i++;
        }
        
        return sum;
    }
};

int main(){

    Solution s;

    long long arr[] = {4,3,1,2,5};
    int n = 5;

    int x = s.sumBetweenTwoKth(arr, n, 1, 3);
    cout << x;
     
    return 0;
}