#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find min path sum from top to bottom of matrix,
// given that you can only move from i -> i-1, i, i+1

// Recursion (req value to base case)
int f1()
{
}

// Memoization
int f2()
{
}

// Tabulation
int f3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){

                int downLeft = INT_MAX;
                if(j>0) downLeft = matrix[i][j] + dp[i-1][j-1];

                int down = matrix[i][j] + dp[i-1][j];

                int downRight = INT_MAX;
                if(j<n-1) downRight = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(downLeft, min(down, downRight));
            }
        }

        int result = INT_MAX;
        for(int i=0; i<n; i++){
            result = min(result, dp[n-1][i]);
        }

        return result;
}

// Space Optimization
int f4()
{
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    return f3(matrix);
}

int main()
{
    vector<vector<int>> matrix = {{2,1,3}, {6,54}, {7,8,9}};
    cout << minFallingPathSum(matrix);

    return 0;
}