#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Given a rod of length ‘N’ units. The rod can be cut into different sizes 
// and each size has a cost associated with it. 
// Determine the maximum cost obtained by cutting the rod and selling its pieces

// Recursion (req value to base case)
// Take price for cutting nth length rod or notTake
int f1(int i, int len, vector<int> &prices)
{
    if(i == 0){
        if(1 <= len) return prices[0];
        return 0;
    }

    int cut = 0; 
    if(i+1 <= len)
        cut = prices[i] + f1(i, len-(i+1), prices); 
    
    int notCut = 0 + f1(i-1, len, prices);

    return max(cut, notCut); 
}

// Memoization
int f2()
{
}

// Tabulation
int f3()
{
}

// Space Optimization
int f4()
{
}

int rodCutting(int n, vector<int> &prices)
{
    return f1(n-1, n, prices);
}

int main()
{
    vector<int> prices = {2, 5, 7, 8, 10};  // prices to cut 1,2,3,4,5 length rod
    int n = 5;  // rod length
    cout << rodCutting(n, prices);

    return 0;
}