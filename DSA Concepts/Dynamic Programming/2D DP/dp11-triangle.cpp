#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Find min path sum from top to bottom of triangle,
// given that you can only move from i -> i, i+2

// Recursion (req value to base case)
// Min path sum from i,j to n-1
int f1(int i, int j, vector<vector<int>>& triangle)
{
    if(i == triangle.size()-1)
        return triangle[i][j];
    
    int down = triangle[i][j] + f1(i+1, j, triangle);
    int downRight = triangle[i][j] + f1(i+1, j+1, triangle);

    return min(down, downRight);
}

// Memoization
int f2(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
{
    if(i == triangle.size()-1)
        return triangle[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down = triangle[i][j] + f2(i+1, j, triangle, dp);
    int downRight = triangle[i][j] + f2(i+1, j+1, triangle, dp);

    return dp[i][j] = min(down, downRight);
}

// Tabulation
int f3(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int i=0; i<n; i++)
        dp[n-1][i] = triangle[n-1][i];
    
    for(int i=n-2; i>=0; i--){
        dp[]
    }
}

// Space Optimization
int f4()
{
}

int Triangle(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    // return f1(0, 0, triangle);

    // vector<vector<int>> dp(n, vector<int> (n, -1));
    // return f2(0, 0, triangle, dp);

    return f3(triangle);
    // return f4(triangle);
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};  // 11
    cout << Triangle(triangle);

    return 0;
}