#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: You have to pick min coins to reach a target amount,
// you can pick any coin, any no of times

// Recursion (req value to base case)
int f1(int i, int amount, vector<int>& coins){

    if(i == 0){
        if(amount % coins[0] == 0) return amount/coins[0];
        else return 1e8;
    }
        
    int take = 1e8;
    if(amount >= coins[i])
        take = 1 + f1(i, amount-coins[i], coins);
    
    int notTake = 0 + f1(i-1, amount, coins);

    return min(take, notTake);
}

// Memoization
int f2(int i, int amt, vector<int>& coins, vector<vector<int>> &dp){

    if(i == 0){
        if(amt % coins[0] == 0) return amt/coins[0];
        else return 1e8;
    }
    if(dp[i][amt] != -1)
        return dp[i][amt];
        
    int take = 1e8;
    if(amt >= coins[i])
        take = 1 + f2(i, amt-coins[i], coins, dp);
    
    int notTake = 0 + f2(i-1, amt, coins, dp);

    return dp[i][amt] = min(take, notTake);
}

// Tabulation
int f3(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));

    for(int amt=0; amt<=amount; amt++){
        if(amt % coins[0] == 0)
            dp[0][amt] = amt/coins[0];
        else
            dp[0][amt] = 1e8;
    }

    for(int i=1; i<n; i++){
        for(int amt=0; amt<=amount; amt++){
            
            int take = 1e8;
            if(amt >= coins[i])
                take = 1 + dp[i][amt-coins[i]];

            int notTake = 0 + dp[i-1][amt];

            dp[i][amt] = min(take, notTake);
        }
    }

    return dp[n-1][amount];
}

// Space Optimization
int f4(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(amount+1, 0), cur(amount+1, 0);

    for(int amt=0; amt<=amount; amt++){
        if(amt % coins[0] == 0)
            prev[amt] = amt/coins[0];
        else
            prev[amt] = 1e8;
    }

    for(int i=1; i<n; i++){
        for(int amt=0; amt<=amount; amt++){
            
            int take = 1e8;
            if(amt >= coins[i])
                take = 1 + cur[amt-coins[i]];

            int notTake = 0 + prev[amt];

            cur[amt] = min(take, notTake);
        }

        prev = cur;
    }

    return prev[amount];
}

int coinChange(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // int ans = f1(n - 1, amount, coins);
    // int ans = f2(n - 1, amount, coins, dp);
    // int ans = f3(amount, coins);
    int ans = f4(amount, coins);
    if (ans >= 1e8)
        return -1;
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(amount, coins);

    return 0;
}