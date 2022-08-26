#include<iostream>

using namespace std;

//Euclid'sAlgorithm (Long Divisions)
int gcd(int a, int  b){

    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){

    cout << "GCD: " << gcd(24,48) << endl;
    // 24 = 2^3 * 3^1
    // 48 = 2^4 * 3^1
    // gcd = 2^3 * 3^1 = 24 

    cout << "LCM: " << 24*48 / gcd(24,48);
    // lcm = a*b / gcd

    return 0;
}