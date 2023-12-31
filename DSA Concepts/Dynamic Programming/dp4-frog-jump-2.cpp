#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Frog wants to reach last stair while jumping and utilizing min energy,
// which is defined as diff b/w heights, given that he can jump i -> i+1, i+2, ... i+k

// Recursion (req value to base case)
// Just add a for loop to incorporate k cases
int f1(int n, vector<int> &h, int k) // min energy to climb nth stair case
{
    if (n == 0)
        return 0;

    int minEnergy = INT_MAX;
    
    for(int i=1; i<=k; i++){
        if(n-i >= 0){
            int energy = f1(n-i, h, k) + abs(h[n] - h[n-i]);
            minEnergy = min(minEnergy, energy);
        }
    }

    return minEnergy;
}

// Memoization
int f2(int n, vector<int> &h, int k, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int minEnergy = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int energy = f1(n - i, h, k) + abs(h[n] - h[n - i]);
            minEnergy = min(minEnergy, energy);
        }
    }

    return dp[n] = minEnergy;
}

// Tabulation
int f3(int n, vector<int> &h, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j >= 0){
                int energy = dp[i-j] + abs(h[i] - h[i - j]);
                minEnergy = min(minEnergy, energy);
            }
        }

        dp[i] = minEnergy;
    }

    return dp[n - 1];
}

// Space Optimization
int f4(int n, vector<int> &h)
{

}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n + 1, -1);
    // return f1(n-1, heights, k);
    // return f2(n-1, heights, k, dp);
    return f3(n, heights, k);
    // return f4(n, heights, k);
}

int main()
{
    int n = 4, k = 3;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights, k);

    return 0;
}