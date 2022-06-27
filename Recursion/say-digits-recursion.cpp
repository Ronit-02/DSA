#include<iostream>
#include<string>

using namespace std;

void sayDigits(int n, string arr[]){

    // Base Case
    if(n == 0)
        return;

    // Recursive Call
    int digit = n % 10;
    sayDigits(n/10, arr);

    // Process
    cout << arr[digit] << " "; 
    
}

int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    sayDigits(929, arr);
    // cout << output << endl;

    return 0;
}