#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Recursion (req value to base case)
int f1(vector<int> &nums)
{
}

// Memoization
int f2()
{
}

// Tabulation
string f3(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    for(int i=0; i<=m; i++) dp[i][0] = 0;
    for(int j=0; j<=n; j++) dp[0][j] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            int a = 0;
            if(s1[i-1] == s2[j-1])
                a = 1 + dp[i-1][j-1];

            int b = dp[i-1][j];
            int c = dp[i][j-1];

            dp[i][j] = max({a, b, c});
        }
    }

    // Extracting SCS from Matrix

    string res;
    int i = m, j = n;

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            res.push_back(s1[i-1]);
            i--;
        }
        else{
            res.push_back(s2[j-1]);
            j--;
        }
    }

    while(i > 0) res.push_back(s1[--i]);
    while(j > 0) res.push_back(s2[--j]);
    
    reverse(res.begin(), res.end());
    return res;
}

// Space Optimization
int f4()
{
}

string commonSupersequence(string &text1, string &text2)
{
    return f3(text1, text2);
}

int main()
{
    string text1 = "bloom";
    string text2 = "blue";
    cout << commonSupersequence(text1, text2);

    return 0;
}