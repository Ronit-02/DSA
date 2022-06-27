#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

//binary to decimal
//00 ... 0001 = 1

int main(){

    int binaryNo;
    cin>> binaryNo;

    int base = 2;    // base or you call it as radix
    int i=0;
    
    int decimalNo = 0;

    for(int n = binaryNo; n!=0; n/=10){

        int lastDigit = n % 10;

        decimalNo += lastDigit * pow(2,i);
        i++;
    }
     
    cout << "Decimal no of " << binaryNo << " is " << decimalNo; 
    return 0;
}