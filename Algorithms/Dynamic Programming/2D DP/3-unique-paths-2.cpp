#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find unique paths from 0,0 -> m-1,n-1 in mxn grid, with some obstacles

// Recursion (req value to base case)
// unique paths from 0,0 till index i,j
int f1(int i, int j, vector<vector<int>> &grid)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(grid[i][j] == 1)
        return 0;

    int up = f1(i-1, j, grid);
    int left = f1(i, j-1, grid);

    return up+left;
}

// Memoization
int f2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(grid[i][j] == 1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = f2(i-1, j, grid, dp);
    int left = f2(i, j-1, grid, dp);

    return dp[i][j] = up+left;
}

// Tabulation
int f3(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(grid[i][j] == 1)
                dp[i][j] = 0;
            else{
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

// Space Optimization
int f4(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n, 0);
    
    for(int i=0; i<m; i++){
        vector<int> cur(n, 0);

        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                cur[j] = 1;
            else if (grid[i][j] == 1)
                cur[j] = 0;
            else{
                cur[j] = prev[j];
                if(j > 0) cur[j] += cur[j-1];
            }
        }
        prev = cur;
    }

    return prev[n-1];
}

int uniquePaths(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // return f1(m-1, n-1, grid);

    // vector<vector<int>> dp(m, vector<int> (n, -1));
    // return f2(m-1, n-1, grid, dp);

    // return f3(m, n, grid);
    return f4(m, n, grid);
}

int main()
{
    // vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    vector<vector<int>> obstacleGrid = {{0,1}, {0,0}};

    cout << uniquePaths(obstacleGrid);

    return 0;
}