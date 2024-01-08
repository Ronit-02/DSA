#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: 

// Recursion (req value to base case)
int f1(int i, int amount, vector<int> &coins){

    if(i == 0){
        if(amount % coins[0] == 0) return 1;
        return 0;
    }

    int take = 0;
    if(coins[i] <= amount) take = f1(i, amount-coins[i], coins);
    
    int notTake = f1(i-1, amount, coins); 

    return take + notTake;
}

// Memoization
int f2(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){

    if(i == 0){
        if(amount % coins[0] == 0) return 1;
        return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount];

    int take = 0;
    if(coins[i] <= amount) take = f2(i, amount-coins[i], coins, dp);
    
    int notTake = f2(i-1, amount, coins, dp); 

    return dp[i][amount] = take + notTake;
}

// Tabulation
int f3(int amount, vector<int>& coins) {
        
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));

    for(int amt=0; amt<=amount; amt++){
        if(amt % coins[0] == 0)
            dp[0][amt] = 1;   
    }

    for(int i=1; i<n; i++){
        for(int amt=0; amt<=amount; amt++){

            int take = 0;
            if(coins[i] <= amt) take = dp[i][amt-coins[i]];
            
            int notTake = dp[i-1][amt]; 

            dp[i][amt] = take + notTake;
        }
    }

    return dp[n-1][amount];
}

// Space Optimization
int f4()
{

}

int coinChange(vector<int> &coins, int amount)
{
    // int n = coins.size();
    // return f1(n-1, amount, coins);

    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // return f2(n - 1, amount, coins, dp);

    return f3(amount, coins);
}

int main()
{
    vector<int> coins = {1, 2, 4};
    int amount = 5;
    cout << coinChange(coins, amount);

    return 0;
}