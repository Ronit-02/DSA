#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Identify if there's a subsequence / subset which sums to k

// Recursion (req value to base case)
// if 0..i has a subsequence that sums to target
bool f1(int i, int k, vector<int> &nums)
{
    if(k == 0)
        return true;
    if(i == 0)
        return (nums[0] == k);

    bool take = false;
    if(nums[i] <= k) take = f1(i-1, k-nums[i], nums);
    bool notTake = f1(i-1, k, nums);

    return take || notTake;
}

// Memoization
bool f2(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
{
    if(k == 0)
        return true;
    if(i == 0)
        return (nums[0] == k);
    if(dp[i][k] != -1)
        return dp[i][k];

    bool take = false;
    if(nums[i] <= k) take = f2(i-1, k-nums[i], nums, dp);
    bool notTake = f2(i-1, k, nums, dp);

    return dp[i][k] = take || notTake;
}

// Tabulation
bool f3(vector<int> &nums, int target)
{   
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool> (target+1, false));

    for(int i=0; i<n; i++)
        dp[i][0] = true;

    if (nums[0] <= target)
        dp[0][nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int k=1; k<=target; k++){

            bool take = false;
            if(nums[i] <= k) take = dp[i-1][k-nums[i]];
            bool notTake = dp[i-1][k];
            
            dp[i][k] = take || notTake;
        }
    }

    return dp[n-1][target];
}

// Space Optimization
bool f4(vector<int> &nums, int target)
{   
    int n = nums.size();
    vector<bool> prev(target+1, 0);
    vector<bool> cur(target + 1, 0);

    prev[0] = cur[0] = true;
    if (nums[0] <= target)
        prev[nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int k=1; k<=target; k++){

            bool take = false;
            if(nums[i] <= k) take = prev[k-nums[i]];
            bool notTake = prev[k];
            
            cur[k] = take || notTake;
        }
        prev = cur;
    }

    return prev[target];
}

bool subsetSum(vector<int> &nums, int k)
{
    int n = nums.size();
    // return f1(n-1, k, nums);

    // vector<vector<int>> dp(n, vector<int> (k+1, -1));
    // return f2(n-1, k, nums, dp);

    return f3(nums, k);
    // return f4(nums, k);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 10;
    cout << subsetSum(nums, k);

    return 0;
}