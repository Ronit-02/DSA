#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void printLCS(string s1, string s2){

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

    // Printing LCS from Matrix

    int size = dp[m][n];
    vector<char> lcs(size, '$');
    int i = m, j = n, idx = size-1;

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs[idx] = s1[i-1];
            idx--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    for(auto ch: lcs)
        cout << ch;
}

int main(){

    string text1 = "abcde";
    string text2 = "abddde";

    printLCS(text1, text2);

    return 0;
}