#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Recursion (req value to base case)
int f1(int i, int j, string &s, string &t){

    if(j < 0)
        return 1;
    if(i < 0) 
        return 0;

    if(s[i] == t[j])
        return f1(i-1, j-1, s, t) + f1(i-1, j, s, t);
    
    return f1(i-1, j, s, t);
}

// Memoization
int f2(int i, int j, string &s, string &t, vector<vector<int>> &dp){

    if(j < 0)
        return 1;
    if(i < 0) 
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = f2(i-1, j-1, s, t, dp) + f2(i-1, j, s, t, dp);
    
    return dp[i][j] = f2(i-1, j, s, t,dp);
}

// Tabulation
int f3(string &s, string &t)
{
    int m = s.size();
    int n = t.size();
    int mod = 1e9+7;

    vector<vector<double>> dp(m+1, vector<double> (n+1, 0)); 

    for(int i=0; i<=m; i++) dp[i][0] = 1;
    for(int j=1; j<=n; j++) dp[0][j] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return (int)dp[m][n];
}

// Space Optimization
int f4()
{
}

int distinctSubsequences(string &s1, string &s2)
{
    // int m = s1.size();
    // int n = s2.size();

    // return f1(m - 1, n - 1, s1, s2);

    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return f2(m - 1, n - 1, s, t, dp);

    return f3(s1, s2);
}

int main()
{
    string s1 = "rabbbit";
    string s2 = "rabbit";  
    cout << distinctSubsequences(s1, s2);   // 3

    return 0;
}