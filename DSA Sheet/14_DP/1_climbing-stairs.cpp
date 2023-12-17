#include<iostream>

using namespace std;

int nthPoint(int n){

    // Base Case
    if(n < 0)
        return 0;     // there is no way to come out of -1, -2th stair
    if(n == 0)
        return 1;    // only 1 way exists from 0th stair to 0th stair

    // Considering 1 case -> " nth stair "
    // you will either jump from (n-1) stair = 1 jump
    // or, you will jump from (n-2) stair = 2 jumps
    int ans = nthPoint(n-1) + nthPoint(n-2);    
    return ans;
}

int main(){

    int output = nthPoint(5);
    cout << output << endl;

    return 0;
}