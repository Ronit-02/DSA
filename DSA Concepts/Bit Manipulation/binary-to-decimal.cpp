#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

// binary to decimal

// 00 ... 0001 = (1)
// 00 ... 0011 = (3)

int main(){

    int n;
    cin>> n;

    int base = 2;    // base or radix
    int decimalNo = 0;

    for(int i=0; n!=0; i++){

        // 1. take out last bit
        int lastDigit = n % 10;

        // 2. add last bit
        decimalNo += lastDigit * pow(2,i);

        // 3. update
        n >> 1;
    }
     
    cout << "Decimal no: " << decimalNo; 
    return 0;
}