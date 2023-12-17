#include<iostream>

using namespace std;

// Ques:
// Count set bits in an integer
// eg. 000 ... 00001101 (13) -> set bits = 3

// Intuition: 
// calculating rsbm at every iteration, subtrating rsbm,
// repeat these steps until it becomes 0

// TC: O(logn)

int main(){

    int n = 13;
    int count = 0;

    while(n != 0){
        int rsbm = n & -n;
        n = n - rsbm;
        count++;
    }

    cout << "Set Bits = " << count;

    return 0;
}