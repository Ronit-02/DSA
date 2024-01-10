#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Frog wants to reach last stair while jumping and utilizing min energy,
// which is defined as diff b/w heights, given that he can only jump from i -> i+1, i+2

// Recursion (req value to base case)
// left subtree would represent i-1
// right subtree would represent i-2
int f1(int n, vector<int> &h) // min energy to climb nth stair case
{
    if(n == 0) 
        return 0;

    int left = f1(n-1, h) + abs(h[n-1] - h[n]);
    
    int right = INT_MAX;
    if(n > 1) right = f1(n-2, h) + abs(h[n-2] - h[n]);

    return min(left, right);
}

// Memoization
int f2(int n, vector<int> &h, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int left = f2(n - 1, h, dp) + abs(h[n - 1] - h[n]);
    
    int right = INT_MAX;
    if(n > 1) right = f2(n - 2, h, dp) + abs(h[n - 2] - h[n]);

    return dp[n] = min(left, right);
}

// Tabulation
int f3(int n, vector<int> &h)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int left = dp[i-1] + abs(h[i-1] - h[i]); 
        
        int right = INT_MAX;
        if(n > 1) right = dp[i-2] + abs(h[i-2] - h[i]);

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

// Space Optimization
int f4(int n, vector<int> &h)
{   
    
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    // return f1(n-1, heights, dp);
    // return f2(n-1, heights, dp);
    // return f3(n, heights);
    return f4(n, heights);
}

int main()
{
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights);

    return 0;
}