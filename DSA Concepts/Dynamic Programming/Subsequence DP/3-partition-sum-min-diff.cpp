#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Question:

// Recursion (req value to base case)
int f1(int i, int s1, int s2, vector<int> &nums)
{
    if(i == 0)
        return abs((s1 + nums[0]) - (s2 - nums[0]));
    
    int take = INT_MAX;
    if(s2 >= nums[i])
        take = f1(i-1, s1+nums[i], s2-nums[i], nums);
    int notTake = f1(i-1, s1, s2, nums);

    return min(take, notTake);
}

// Memoization
int f2()
{
}

// Tabulation
int f3(vector<int> &nums)
{
    int n = nums.size(), sum=0;
    for(int i=0; i<n; i++)
        sum += nums[i];

    int target = sum;

    vector<vector<bool>> dp(n, vector<bool> (target+1, false));

    for(int i=0; i<n; i++)
        dp[i][0] = true;

    if(nums[0] <= target) 
        dp[0][nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int k=1; k<=target; k++){

            bool take = false;
            if(nums[i] <= k) take = dp[i-1][k-nums[i]];
            bool notTake = dp[i-1][k];
            
            dp[i][k] = take || notTake;
        }
    }

    int mini = INT_MAX;

    for(int s1=0; s1<sum/2; s1++){
        if(dp[n-1][s1] == true){
            int s2 = sum - s1;
            mini = min(mini, abs(s1-s2));
        }
    }

    return mini;
}

// Space Optimization
int f4()
{
}

int minimumDifference(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for(int i=0; i<n; i++)
        sum += nums[i];

    return f1(n-1, 0, sum, nums);
}

int main()
{
    vector<int> nums = {3, 9, 7, 3}; // 2
    cout << minimumDifference(nums);

    return 0;
}