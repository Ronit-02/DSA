#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// Recursion
// Intuition: remember recursion is required value to base case
int f(int i, vector<int> &h){

    if(i == 0) return 0;   // no cost at the same spot

    int left = f(i-1, h) + abs(h[i] - h[i-1]);
    int right = INT_MAX; 
    if(i > 1) right = f(i-2, h) + abs(h[i] - h[i-2]);

    return min(left, right);
}

// Memoization
int f1(int i, vector<int> &h, vector<int> &dp){

    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int left = f1(i-1, h, dp) + abs(h[i] - h[i-1]);
    int right = INT_MAX; 
    if(i > 1) right = f1(i-2, h, dp) + abs(h[i] - h[i-2]);

    return dp[i] = min(left, right);
}

// Tabulation
int f2(int n, vector<int> &h, vector<int> &dp){

    dp[0] = 0;

    for(int i=1; i<n; i++){
        int left = dp[i-1] + abs(h[i] - h[i-1]);

        int right = INT_MAX;
        if(i > 1) right = dp[i-2] + abs(h[i] - h[i-2]);

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

// Space Optimization
int f3(int n, vector<int> &h){

    int prev = 0, prev2 = 0;

    for(int i=1; i<n; i++){
        int left = prev + abs(h[i] - h[i-1]);

        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(h[i] - h[i-2]);

        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int frogJump(int n, vector<int> &heights){

    vector<int> dp(n, -1);
    // return f1(n-1, heights, dp);
    // return f2(n, heights, dp);
    return f3(n, heights);
}

int main(){
    
    int n = 4;
    vector<int> heights = {10,20,30,10};

    cout << frogJump(n, heights);
    
    return 0;
}