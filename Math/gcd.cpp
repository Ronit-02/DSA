#include<iostream>

using namespace std;

//Euclid'sAlgorithm
int gcd(int a, int  b){

    // base cases
    if(a==0)
        return b;
    if(b==0)
        return a;
    
    if(a >= b)
        gcd(a-b, b);
    else
        gcd(a,b-a);
}

int main(){

    cout<< gcd(24,48);

    return 0;
}