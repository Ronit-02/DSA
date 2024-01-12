#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Recursion (req value to base case)
int f1(int i, int j, string &s, string &t){

    if(i < 0) return j+1;
    if(j < 0) return i+1;

    if(s[i] == t[j])
        return f1(i-1, j-1, s, t);
    
    // insert, delete, replace
    return 1 + min({
        f1(i, j-1, s, t), 
        f1(i-1, j, s, t), 
        f1(i-1, j-1, s, t)
    });
}

// Memoization
int f2()
{
}

// Tabulation
int f3(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    for(int j=0; j<=n; j++) dp[0][j] = j;
    for(int i=0; i<=m; i++) dp[i][0] = i;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({
                    dp[i][j-1],
                    dp[i-1][j],
                    dp[i-1][j-1]
                });
            }
        }
    }

    return dp[m][n];
}

// Space Optimization
int f4()
{
}

int editDistance(string &word1, string &word2)
{
    int m = word1.size();
    int n = word2.size();

    return f1(m-1, n-1, word1, word2);
}

int main()
{
    string s1 = "horse";
    string s2 = "ros";
    cout << editDistance(s1, s2);  // 3

    return 0;
}