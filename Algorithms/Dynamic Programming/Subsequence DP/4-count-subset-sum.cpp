#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find out ways to attain target sum

// Recursion (req value to base case)
// From '0...i' how many subsets with sum 'k' we can form!!
int f1(int i, int k, vector<int> &nums)
{
    if(i == 0){
        if(k == 0 && nums[0] == 0) return 2;
        if(k == 0 || k == nums[0]) return 1;
        return 0;
    }
    
    int take = 0;
    if(nums[i] <= k) 
        take = f1(i-1, k-nums[i], nums);
    int notTake = f1(i-1, k, nums);

    return take + notTake;
}

// Memoization
int f2(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
{
    if(i == 0){
        if(k == 0 && nums[0] == 0) return 2;
        if(k == 0 || k == nums[0]) return 1;
        return 0;
    }
    if(dp[i][k] != -1)
        return dp[i][k];
    
    int take = 0;
    if(nums[i] <= k) 
        take = f2(i-1, k-nums[i], nums, dp);
    int notTake = f2(i-1, k, nums, dp);

    return dp[i][k] = take + notTake;
}

// Tabulation
int f3(vector<int> &nums, int target)
{   
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));

    if(nums[0] == 0){
        dp[0][0] = 2;
    }
    else   
        dp[0][0] = 1;

    if(nums[0] <= target && nums[0] != 0)
        dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int k=0; k<=target; k++){

            int take = 0;
            if(nums[i] <= k) take = dp[i-1][k-nums[i]];
            int notTake = dp[i-1][k];

            dp[i][k] = take + notTake;
        }
    }

    return dp[n-1][target];
}

// Space Optimization
int f4()
{

}

int countSubsetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    // return f1(n-1, target, nums);

    // vector<vector<int>> dp(n, vector<int> (target+1, -1));
    // return f2(n-1, target, nums, dp);

    return f3(nums, target);
}

int main()
{
    vector<int> nums = {0,0,1};  // 4
    int target = 1;
    cout << countSubsetSum(nums, target);

    return 0;
}