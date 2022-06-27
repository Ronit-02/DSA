#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>

using namespace std;

class Solution {
public:
    // Recursion + Memoization Approach
    int numSquares(int n) {

        int a = sqrt(n);
        if(a*a == n)
            return 1;

        if(n <= 3)
            return n;        
        
    }
};


int main(){

    Solution s;
    
    int output = s.numSquares(10);
    cout<<output;
     
    return 0;
}