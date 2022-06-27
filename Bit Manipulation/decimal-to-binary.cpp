#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

//decimal to binary
//1 = 0001

int main(){

    int n;
    cin >> n;

    int ans = 0;
    int i = 0;

    while(n != 0){

        int lastBit = n & 1;
        
        ans = ( lastBit * pow(10,i) ) + ans;

        n = n>>1;
        i++;
    }
    
    cout << ans;

    return 0;
}