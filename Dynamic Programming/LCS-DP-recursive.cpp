#include<iostream>
#include<string>

using namespace std;

int LCS(string x, string y, int m, int n){

    //base codition
    if(m==0 || n==0)
        return 0;       // length of common subsequence which is empty set is 0

    //conditions using the choice diagram
    if(x[m-1] == y[n-1]){
        return 1 + LCS(x, y, m-1, n-1);
    }

    if(x[m-1] != y[n-1]){
        return max( LCS(x, y, m-1, n) , LCS(x, y, m, n-1) );
    }

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