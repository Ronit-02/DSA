#include<iostream>

using namespace std;

int knapsack(int wt[], int val[], int W, int n){

    //declaring DP matrix
    int t[100][100];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
        
            //base codition   ->   initialization        
            if(i==0 || j==0)
                t[i][j] = 0;

            //conditions using the choice diagram   ->   Iterative Version
            if(wt[i-1] <= j){
                t[i][j] = max( val[i-1] + t[i-1][j- wt[i-1]] , t[i-1][j]);
            }

            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){

    int wt[] = {1,3,7,5};
    int val[] = {1,3,4,6};

    int W = 8;  
    int n = 4;

    int op = knapsack(wt, val, W, n);       // returning max profit
    cout << op;

    return 0;
}