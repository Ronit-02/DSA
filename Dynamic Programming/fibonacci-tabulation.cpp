#include<iostream>
#include<vector>

using namespace std;

// TC: O(n)
// SC: O(n)
// Tabulation (bottom-up approach)
int f(int n, vector<int> &dp){

    if(n <= 1) return n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main(){

    int n=6;

    // fibonacci (0 1 1 2 3 5 8 ...)
    vector<int> dp(n+1, -1);
    cout << f(n, dp);

    return 0;
}