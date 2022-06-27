#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    // const int D = 1000;
    int t[1000][1000];

int LCS(string x, string y, int m, int n){

    //base codition
    if(m==0 || n==0)
        return 0;       // lenghth of common subsequence which is empty set is 0

    if(t[m][n] != -1)
        return t[m][n];

    //conditions using the choice diagram
    if(x[m-1] == y[n-1]){
        return t[m][n] =  1 + LCS(x, y, m-1, n-1);
    }

    else{
        return t[m][n] =  max( LCS(x, y, m-1, n) , LCS(x, y, m, n-1) );
    }

}
    
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        // initializing memoization table
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                t[i][j] = -1;
            }
        }
        
        // calling function
        int len = LCS(word1, word2, m, n);
        
        int ans = (m-len) + (n-len);
        
        return ans;
    }
};

int main(){

    string x = "prosperity";
    string y = "properties";

    Solution s;
    int output = s.minDistance(x, y);
    cout<<output;
     
    return 0;
}