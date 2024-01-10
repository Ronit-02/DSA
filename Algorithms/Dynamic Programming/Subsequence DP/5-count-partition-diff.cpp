#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find out ways to partition an array into subsets,
// such that sum of subsets diff equals target

// Recursion (req value to base case)
int f1(vector<int> &nums)
{
}

// Memoization
int f2()
{
}

// Tabulation
int f3(vector<int> &nums, int diff)
{
    int n = nums.size(), tsum = 0;
    for(int i=0; i<n; i++)
        tsum += nums[i];

    int target = tsum/2; 

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

    for(int s1=0; s1<=target; s1++){
        int s2 = tsum - s1;
        if(s1-s2 == diff || s2-s1 == diff)
            return dp[n][s1];
    }

    return 0;
}

// Space Optimization
int f4()
{
}

int canPartitionDiff(vector<int> &nums, int &target)
{
    return f3(nums, target);
}

int main()
{
    vector<int> nums = {1, 2, 4};
    int target = 2;
    cout << canPartitionDiff(nums, target);

    return 0;
}