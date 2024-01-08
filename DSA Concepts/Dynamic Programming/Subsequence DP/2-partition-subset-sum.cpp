#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Tell if we can partition array into subsets that equals sum

// Recursion (req value to base case)
// if 0...i can be partitioned in equal subsets
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
bool f2()
{
}

// Tabulation
bool f3()
{
}

// Space Optimization
bool f4()
{
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for(int i=0; i<n; i++) 
        sum += nums[i];
    
    if(sum % 2 != 0)
        return false;

    return f1(n-1, sum/2, nums);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);

    return 0;
}