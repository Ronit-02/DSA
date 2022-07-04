#include<iostream>

using namespace std;

void multiply(int F[2][2], int M[2][2]){

    int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

void power(int F[2][2], int n){
    
    if(n == 1)
        return;
    
    int M[2][2] = {{1,1},{1,0}}; 

    power(F, n/2);
    multiply(F, F);
    
    if(n % 2 != 0)  // if n = odd
        multiply(F, M);
}

int fib(int n){

    int F[2][2] = {{1,1},{1,0}};    // fibonacci matrix

    if(n == 0)
        return 0;

    power(F, n);   // power of n

    return F[0][1];    // Fn
}

int main(){

    int n = 9;
    cout << " " << fib(n);

    return 0;
}