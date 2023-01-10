#include<iostream>

using namespace std;

const int D = 1000; // DP - matrix dimensions
int t[D][D]; // DP - matrix

int knapsack(int wt[], int val[], int W, int n){

    //base codition
    if(W == 0 || n == 0)
        return 0;

    if(t[W][n] != -1)
        return t[W][n];

    //conditions using the choice diagram
    if(wt[n-1] <= W)                 // if we got 2 choices, we take it or we don't take it
        return t[W][n] = max( val[n-1] + knapsack(wt, val, W - wt[n-1], n-1) , 
                    0 + knapsack(wt, val, W, n-1) );
    
    else if(wt[n-1] > W)             // if the weight is greater, there is no sense in taking that weight
        return t[W][n] = knapsack(wt, val, W, n-1);

}

int main(){

    int wt[] = {1,3,7,5};
    int val[] = {1,3,4,6};

    int W = 8;  
    int n = 4;

    //matrix inisialization
    for(int i=0; i<=W; i++){
        for(int j=0; j<=n; j++){
            t[i][j] = -1;
        }
    }

    int op = knapsack(wt, val, W, n);       // returning max profit
    cout << op;

    return 0;
}