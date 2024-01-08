#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Thief wants to steal maximum value items,
// but he can carry a fixed weight of items

// Recursion (req value to base case)
int f1(int i, int w, vector<int> &wt, vector<int> &val)
{
    if(i == 0){
        if(wt[0] <= w) return val[0];
        return 0;
    }

    int take = INT_MIN;
    if(w >= wt[i]) take = val[i] + f1(i-1, w-wt[i], wt, val);
    int notTake = 0 + f1(i-1, w, wt, val);

    return max(take, notTake);
}

// Memoization
int f2(int i, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if(i == 0){
        if(wt[0] <= w) return val[0];
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];

    int take = INT_MIN;
    if(w >= wt[i]) take = val[i] + f2(i-1, w-wt[i], wt, val, dp);
    int notTake = 0 + f2(i-1, w, wt, val, dp);

    return dp[i][w] = max(take, notTake);
}

// Tabulation
int f3(int maxWeight, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    
    for(int w = wt[0]; w <= maxWeight; w++)
        dp[0][w] = val[0];

    for(int i=1; i<n; i++){
        for(int w=0; w<=maxWeight; w++){

            int take = INT_MIN;
            if (w >= wt[i])
                take = val[i] + dp[i-1][w - wt[i]];
            int notTake = 0 + dp[i-1][w];

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n-1][maxWeight];
}

// Space Optimization
int f4()
{
}

int knapsack(int &maxWeight, vector<int> &weight, vector<int> &value)
{
    int n = weight.size();
    // return f1(n-1, maxWeight, weight, value);

    // vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    // return f2(n-1, maxWeight, weight, value, dp);

    return f3(maxWeight, weight, value);
}

int main()
{   
    vector<int> weight = {1, 2, 4};
    vector<int> value = {1, 1, 2};
    int maxWeight = 5;
    cout << knapsack(maxWeight, weight, value);

    return 0;
}