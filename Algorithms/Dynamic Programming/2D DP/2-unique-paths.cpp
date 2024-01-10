#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find unique paths from 0,0 -> m-1,n-1 in mxn grid

// Recursion (req value to base case)
// unique paths from 0,0 till index i,j
int f1(int i, int j)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;

    int up = f1(i-1, j);
    int left = f1(i, j-1);

    return up+left;
}

// Memoization
int f2(int i, int j, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = f2(i-1, j, dp);
    int left = f2(i, j-1, dp);

    return dp[i][j] = up+left;
}

// Tabulation
int f3(int m, int n)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[i][j] = 1;
            else{
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

// Space Optimization
int f4(int m, int n)
{
    vector<int> prev(n, 0);
    
    for(int i=0; i<m; i++){
        vector<int> cur(n, 0);

        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                cur[j] = 1;
            else{
                cur[j] = prev[j];
                if(j > 0) cur[j] += cur[j-1];
            }
        }
        prev = cur;
    }

    return prev[n-1];
}

int uniquePaths(int m, int n)
{
    // return f1(m-1, n-1);

    // vector<vector<int>> dp(m, vector<int> (n, -1));
    // return f2(m-1, n-1, dp);

    // return f3(m, n);
    return f4(m, n);
}

int main()
{
    int m = 3, n = 7;
    cout << uniquePaths(m, n);

    return 0;
}