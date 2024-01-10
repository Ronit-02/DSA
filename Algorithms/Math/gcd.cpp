#include<iostream>
using namespace std;

// GCD/HCF of 2 numbers (largest no that divides both of them)
// 24 = 2^3 * 3^1
// 48 = 2^4 * 3^1
// gcd = 2^3 * 3^1 = 24 (take all commons)

// Brute Force, repeated subtraction / O(min(a,b))
int gcd1(int a, int b){

    int res = min(a, b);
    while(res > 0){
        if(a%res == 0 && b%res == 0){
            return res;
        }
        res--;
    }
    return 1;
}

// Euclid'sAlgorithm (Long Subtraction) / O(min(a,b))
int gcd2(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;

    if(a == b)
        return a;
    if(a > b)
        return gcd2(a-b, b);
    return gcd2(a, b-a);
}

// Improvised Euclid'sAlgorithm (Long Divisions) / O(log(min(a,b)))
int gcd3(int a, int  b){

    if(b == 0)
        return a;
    return gcd3(b, a%b);
}

int main(){

    // lcm(a,b) = a*b / gcd(a,b)
    cout << "GCD: " << gcd3(24,48) << endl;
    cout << "LCM: " << 24*48 / gcd3(24,48);

    return 0;
}