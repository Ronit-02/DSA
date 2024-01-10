#include<iostream>

using namespace std;

// RSBM = Right most set bit mask
// eg. 
// 000 ... 00001010 (10) -> rsbm = 000 ... 00000010 (2)
// 000 ... 00001100 (12) -> rsbm = 000 ... 00000010 (4)

int main(){

    int n;
    cin >> n;

    int rsbm = n & -n;   // n + (2's compliment)
    cout << rsbm;

    return 0;
}