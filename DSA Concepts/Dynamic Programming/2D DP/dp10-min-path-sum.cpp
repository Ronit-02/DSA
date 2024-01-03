#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find minimum path sum from top-left to right-bottom,
// given that you can only move down and right

// Recursion (req value to base case)
// Min path sum from 0,0 -> i,j
int f1(int i, int j, vector<vector<int>> &grid)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return INT_MAX;

    int up = f1(i-1, j, grid);
    int left = f1(i, j-1, grid);

    return grid[i][j] + min(up, left);
}

// Memoization
int f2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = f2(i-1, j, grid, dp);
    int left = f2(i, j-1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up, left);
}

// Tabulation
int f3(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[i][j] = grid[i][j];
            else{
                int up = INT_MAX;
                int left = INT_MAX;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[m-1][n-1];
}

// Space Optimization
int f4(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, INT_MAX);

    for(int i=0; i<m; i++){
        vector<int> cur(n, 0);
        
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                cur[j] = grid[i][j];
            else{
                int up = INT_MAX;
                int left = INT_MAX;
                up = prev[j];
                if(j>0) left = cur[j-1];

                cur[j] = grid[i][j] + min(up, left);
            }
        }

        prev = cur;
    }

    return prev[n-1];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // return f1(m-1, n-1, grid);

    // vector<vector<int>> dp(m, vector<int> (n, -1));
    // return f2(m-1, n-1, grid, dp);

    // return f3(grid);
    return f4(grid);
}

int main()
{
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << minPathSum(grid);

    return 0;
}