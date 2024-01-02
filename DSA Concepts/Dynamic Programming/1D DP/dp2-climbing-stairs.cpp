#include<iostream>
#include<vector>

using namespace std;

// Question: Find out ways in which you can reach nth stair, 
//given that you can only jumb 1 or 2 stairs at a time

// Recursion (req ans to base case) 

// ways to climb nth stair is decided by ways to climb (n-1)st and (n-2)nd stair
// 0th stair = 1way
// 1st stair = 1way
// 2nd stair = climb from 0th or 1st stair = 2ways
int f1(int n){    // ways to climb nth stair case

    if(n <= 1) 
        return 1;

    return f1(n-1) + f1(n-2);
}

// Memoization
int f2(int n, vector<int> &dp){

    if (n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = f2(n-1, dp) + f2(n-2, dp);
}

// Tabulation
int f3(int n){

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){

    int n = 3;
    // vector<int> dp(n + 1, -1);

    int ans = f3(n);
    cout << ans;

    return 0;
}