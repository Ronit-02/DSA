#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    void multiply(int a[3][3], int b[3][3]){
        
        int mul[3][3];      // we'll save multiplication in new matrix
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                
                mul[i][j] = 0;
                for (int k=0; k<3; k++)
                    mul[i][j] += a[i][k]*b[k][j];
            }
        }
        
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                a[i][j] = mul[i][j];  // Updating our matrix
    }
    
    // through binary exponentiation or power paradigm
    void power(int F[3][3], int n){
        
        int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};

        if (n == 1)
            return;

        power(F, n/2);
        multiply(F, F);

        if (n % 2 != 0)     // if n = odd
            multiply(F, M);
    } 
    int tribonacci(int n){

        int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};    // as, a=1, b=1, c=1

        // Base cases
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        power(F, n-2);      // we have to multiply (n-2) times
        
        int ans = F[0][0] + F[0][1];       // F[0][0] * 1 + F[0][1] * 1 + F[0][2] * 0
        return ans;
    }
};

int main(){

    Solution s;
    int output = s.tribonacci(3);
    cout<<output;
     
    return 0;
}