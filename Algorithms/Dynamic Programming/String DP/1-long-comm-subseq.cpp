#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Longest Common Subsequence

// Recursion (req value to base case)
int f1(int i, int j, string &s1, string &s2){

    if(i < 0 || j < 0)
        return 0;

    int a = 0;
    if(s1[i] == s2[j])
        a = 1 + f1(i-1, j-1, s1, s2);

    int b = f1(i-1, j, s1, s2);
    int c = f1(i, j-1, s1, s2);

    return max({a, b, c});
}

// Memoization
int f2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int a = 0;
    if(s1[i] == s2[j])
        a = 1 + f2(i-1, j-1, s1, s2, dp);

    int b = f2(i-1, j, s1, s2, dp);
    int c = f2(i, j-1, s1, s2, dp);

    return dp[i][j] = max({a, b, c});
}

// Tabulation
int f3(string &s1, string &s2)
{

}

// Space Optimization
int f4()
{
}

int LCS(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    return f1(m-1, n-1, text1, text2);

    vector<vector<int>> dp(m, vector<int> (n, -1));
    return f2(m-1, n-1, text1, text2, dp);

    return f3(text1, text2);
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    cout << LCS(text1, text2);

    return 0;
}