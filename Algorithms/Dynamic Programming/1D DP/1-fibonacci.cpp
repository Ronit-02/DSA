#include<iostream>
#include<vector>

using namespace std;

// Recursion (think req value to base case)
int f1(int n){
    
    if(n <= 1) return n;

    return f1(n-1) + f1(n-2);
}

// Memoization (top-down)
// TC: O(n)
// SC: array + recursion stack: O(n) + O(n) = O(2n)
int f2(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f2(n-1,dp) + f2(n-2,dp);
}

// Tabulation (bottom-up)
// TC: O(n)
// SC: O(n)
int f3(int n){

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n-1];
}

// Space Optimization
// TC: O(n)
// SC: O(1)
int f4(int n){

    int prev2 = 0;
    int prev = 1;

    for(int i=2; i < n; i++){
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main(){

    // fibonacci (0 1 1 2 3 5 8 ...)
    int n = 3;
    
    vector<int> dp(n+1, -1);
    // cout << f2(n, dp);
    cout << f4(n);

    return 0;
}