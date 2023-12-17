#include<iostream>
#include<string>

using namespace std;

const int D = 1000;
int t[D][D];

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

int main(){

    string x = "prosperity";
    int m = x.length();

    string y = "properties";
    int n = y.length();  

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            t[i][j] = -1;
        }
    }

    int op = LCS(x, y, m, n);       // returning length of max subsequence
    cout << op;

    return 0;
}