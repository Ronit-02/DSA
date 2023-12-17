#include<iostream>
#include<string>

using namespace std;

int LCS(string x, string y, int m, int n){

    int t[m+1][n+1];

    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){

            //base codition   ->   initialization
            if(i==0 || j==0)
                t[i][j] = 0;

            //conditions using the choice diagram
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }

            if(x[i-1] != x[j-1]){
                t[i][j] = max( t[i-1][j] , t[i][j-1] );
            }
        }
    }
    return t[m][n];

}

int main(){

    string x = "ronit";
    int m = 5;

    string y = "khatri";
    int n = 6;  

    int op = LCS(x, y, m, n);       // returning length of max subsequence
    cout << op;

    return 0;
}