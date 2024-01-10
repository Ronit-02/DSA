#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Recursion (req value to base case)
int f1(int i, int j, string &s)
{
    if(i > j) return 0;
    if(i == j) return 1;

    if(s[i] == s[j])
        return 2 + f1(i+1, j-1, s);
    else
        return max(f1(i+1, j, s), f1(i, j-1, s));
}

// Memoization
int f2(int i, int j, string &s, vector<vector<int>> &dp)
{
    if(i > j) return 0;
    if(i == j) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == s[j])
        return dp[i][j] = 2 + f2(i+1, j-1, s, dp);
    else
        return dp[i][j] = max(f2(i+1, j, s, dp), f2(i, j-1, s, dp));
}

// Tabulation
int f3(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    
    for(int i=0; i<=n/2; i++){
        for(int j=n; j>=n/2; j--){
            if(i == j){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=0; i<=n/2; i++){
        for(int j=n; j>=n/2; j--){
            if(s[i] == s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Space Optimization
int f4()
{
}

int palindromicSubseq(string &s)
{
    int n = s.size();
    // return f1(0, n-1, s);

    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // return f2(0, n-1, s, dp);

    return f3(s);
}

int main()
{
    string str = "bbabb";
    cout << palindromicSubseq(str);

    return 0;
}