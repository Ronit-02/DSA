#include<iostream>
#include<vector>

using namespace std;

// Recursion
int f(int n){
    
    if(n <= 1) return n;

    return f(n-1) + f(n-2);
}

// Memoization (top-down)
// TC: O(n)
// SC: array + recursion stack: O(n) + O(n) = O(2n)
int f1(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f1(n-1,dp) + f1(n-2,dp);
}

// Tabulation (bottom-up)
// TC: O(n)
// SC: O(n)
int f2(int n, vector<int> &dp){

    if(n <= 1) return n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// Space Optimization
// TC: O(n)
// SC: O(1)
int f3(int n){

    if(n <= 1) return n;

    int prev2=0, prev=1;

    for(int i=2; i<n+1; i++){
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){

    // fibonacci (0 1 1 2 3 5 8 ...)
    int n = 4;
    
    vector<int> dp(n+1, -1);
    // cout << f1(n, dp);
    cout << f3(n);

    return 0;
}