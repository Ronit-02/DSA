#include <iostream>

using namespace std;

int modularExponentiation(int x, int n, int m) {
	
    int res = 1;
    
    while(n > 0){
        
        if(n&1){     // odd value
            res = ( 1LL * (res)%m * (x)%m)%m;
        }
        x  = ( 1LL * (x)%m * (x)%m)%m;
        n = n>>1;     // n/2
    }
    return res;
}

int main(){

    return 0;
}