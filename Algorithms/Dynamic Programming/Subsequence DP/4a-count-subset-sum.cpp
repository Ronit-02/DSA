#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Negative Indexing Approach of Same Ques

// Recursion (req value to base case)
int f1(int i, int k, vector<int> &nums)
{
    if(i == -1){
        if(k == 0) return 1;
        else return 0;
    }
    
    int take = 0;
    if(nums[i] <= k) 
        take = f1(i-1, k-nums[i], nums);
    int notTake = f1(i-1, k, nums);

    return take + notTake;
}

// Memoization
int f2()
{}

// Tabulation
int f3(vector<int> &nums, int target)
{  
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int k=0; k<=target; k++){

            int take = 0;
            if(nums[i-1] <= k) take = dp[i-1][k-nums[i-1]];
            int notTake = dp[i-1][k];

            dp[i][k] = take + notTake;
        }
    }

    return dp[n][target];
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