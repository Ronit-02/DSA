#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Longest Common Substring (consecutive)

// Tabulation
int LCS(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    int maxi = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            if(s1[i-1] == s2[j-1]){
                if(dp[i-1][j-1] != 0)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else    
                    dp[i][j] = 1;

                maxi = max(maxi, dp[i][j]);
            }
        }
    }

    return maxi;
}

int main()
{
    string text1 = "abcde";
    string text2 = "aecde";
    cout << LCS(text1, text2);

    return 0;
}