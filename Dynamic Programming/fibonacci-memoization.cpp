#include<iostream>
#include<vector>

using namespace std;

// TC: O(n)
// SC: O(2n)
// Memoization (top-down approach)
int f(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1,dp) + f(n-2,dp);
}

int main(){

    int n=5;

    // fibonacci (0 1 1 2 3 5 8 ...)
    vector<int> dp(n+1, -1);
    cout << f(n, dp);

    return 0;
}