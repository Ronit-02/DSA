#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Calculate max sum of non adjacenet subsequence

// Recursion (req value to base case)
int f1(int i, vector<int> &nums)  // maximum subsequence from 0 ... n
{
    if(i < 0) 
        return 0;
    if(i == 0) 
        return nums[i];

    int pick = nums[i] + f1(i-2, nums);
    int notPick = 0 + f1(i-1, nums); 

    return max(pick, notPick);  
}

// Memoization
int f2(int i, vector<int> &nums, vector<int> &dp)
{
    if (i < 0)
        return 0;
    if (i == 0)
        return nums[i];
    if(dp[i] != -1)
        return dp[i];

    int pick = nums[i] + f2(i-2, nums, dp);
    int notPick = 0 + f2(i-1, nums, dp);

    return dp[i] = max(pick, notPick);
}

// Tabulation
int f3(int n, vector<int> &nums)
{   
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        
        int pick = nums[i]; 
        if(i > 1) pick += dp[i-2];
        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }

    return dp[n-1];
}

// Space Optimization
int f4(int n, vector<int> &nums)
{   
    int prev = nums[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++){

        int pick = nums[i]; 
        if(i > 1) pick += prev2;
        int notPick = prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    // return f1(n-1, nums);
    vector<int> dp(n+1, -1);
    // return f2(n, nums, dp);
    return f4(n, nums);
}

int main()
{
    vector<int> nums = {1, 2, 4};
    cout << maxNonAdjSum(nums);

    return 0;
}