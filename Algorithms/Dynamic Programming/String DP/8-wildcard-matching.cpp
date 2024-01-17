#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Recursion (req value to base case)
bool f1(int i, int j, string &s, string &p){

    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int idx=0; idx<=j; idx++){
            if(p[idx] != '*')
                return false;
        }
        return true;
    }

    if(p[j] == '?' || s[i] == p[j])
        return f1(i-1, j-1, s, p);
    
    if(p[j] == '*'){
        int a = f1(i-1, j-1, s, p); // * is alphabet
        int b = f1(i, j-1, s, p);   // * is empty string
        int c = f1(i-1, j, s, p);   // * is string

        return a | b | c;
    }

    return false;
}

// Memoization
bool f2(int i, int j, string &s, string &p, vector<vector<int>> &dp){

    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int idx=0; idx<=j; idx++){
            if(p[idx] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    if(p[j] == '?' || s[i] == p[j])
        return dp[i][j] = f2(i-1, j-1, s, p, dp);
    
    if(p[j] == '*'){
        int a = f2(i-1, j-1, s, p, dp); // * is alphabet
        int b = f2(i, j-1, s, p, dp);   // * is empty string
        int c = f2(i-1, j, s, p, dp);   // * is string

        return dp[i][j] = a | b | c;
    }

    return dp[i][j] = false;
}

// Tabulation
int f3()
{
}

// Space Optimization
int f4()
{
}

int wildcardMatching(string &s, string &p)
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return f2(m-1, n-1, s, p, dp);
}

int main()
{
    string text = "ray";
    string pattern = "?ay";
    cout << wildcardMatching(text, pattern); // true

    return 0;
}