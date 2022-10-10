#include<iostream>
#include<vector>

using namespace std;

// TC: O(n)
// SC: O(1)
// Space Optimization
int f(int n){

    if(n <= 1) return n;

    int prev2=0, prev=1, curr=0;

    for(int i=2; i<n+1; i++){
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){

    int n=4;

    // fibonacci (0 1 1 2 3 5 8 ...)
    cout << f(n);

    return 0;
}