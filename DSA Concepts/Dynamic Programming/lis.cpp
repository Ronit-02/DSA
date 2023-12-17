#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int LIS(vector<int> nums, int idx, int previdx, vector<vector<int>>&dp){
        
        int n = nums.size();
        // base condition
        if(idx == n)
            return 0;
        
        // Using memoization
        if(dp[idx][previdx + 1] != -1)
            return dp[idx][previdx + 1];
        
        // not take
        int len = 0 + LIS(nums, idx + 1, previdx, dp);
        
        // take
        if(previdx == -1 || nums[idx] > nums[previdx]){
            len = max(len, 1 + LIS(nums, idx + 1, idx, dp));
        }
        
        return dp[idx][previdx + 1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int len = LIS(nums, 0, -1, dp);
        
        return len;
    }
};

int main(){

    Solution s;

    vector<int> arr = {10,9,2,5,3,7,101,18};

    int output = s.lengthOfLIS(arr);
    cout<<output;
     
    return 0;
}