#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Bob and Charlie wants to collect maximum cherries from the grid,
// given that they start from 0,0 and 0,n-1 and only 1 pick from 1 cell

// Recursion (req value to base case)
// Max cherries to pick when starting from (i,j1) and (i,j2)
int f1(int i, int j1, int j2, vector<vector<int>> &grid)
{
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        return INT_MIN;
    
    if(i == grid.size() - 1){
        if(j1 == j2) 
            return grid[i][j1];
        else 
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = INT_MIN;

    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2)
                maxi = max(maxi, grid[i][j1] + f1(i + 1, j1 + dj1, j2 + dj2, grid));
            else
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f1(i + 1, j1 + dj1, j2 + dj2, grid));
        }
    }

    return maxi;
}

// Memoization
int f2(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        return INT_MIN;
    
    if(i == grid.size() - 1){
        if(j1 == j2) 
            return grid[i][j1];
        else 
            return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;

    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2)
                maxi = max(maxi, grid[i][j1] + f2(i + 1, j1 + dj1, j2 + dj2, grid, dp));
            else
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f2(i + 1, j1 + dj1, j2 + dj2, grid, dp));
        }
    }

    return dp[i][j1][j2] = maxi;
}

// Tabulation
int f3(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

    for(int j1=0; j1<n; j1++){
        for(int j2=0; j2<n; j2++){
            if(j1 == j2)
                dp[m-1][j1][j2] = grid[m-1][j1];
            else 
                dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
        }
    }

    for(int i=m-2; i>=0; i--){
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                int maxi = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        if(j1 == j2 && j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n)
                            maxi = max(maxi, grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2]);

                        else if(j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n)
                            maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1];
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // return f1(0, 0, n-1, grid);

    // vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
    // return f2(0, 0, n-1, grid, dp);

    return f3(grid);
}

int main()
{
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}}; // 24
    cout << cherryPickup(grid);

    return 0;
}