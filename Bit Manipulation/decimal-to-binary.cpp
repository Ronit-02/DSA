#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

// decimal to binary

// 1 = 0001
// right shift: 0001 >> 1 = 0000
// left shift:  0001 << 1 = 0010

int main(){

    int n;
    cin >> n;

    int binary = 0;
    int i = 0;

    for(int i=0; n != 0; i++){

        // 1. take out last bit
        int lastBit = n & 1;
        
        // 2. add last bit
        binary = ( lastBit * pow(10,i) ) + binary;

        // 3. update n
        n = n>>1;
    }
    
    cout << binary;

    return 0;
}