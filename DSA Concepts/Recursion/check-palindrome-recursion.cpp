#include<iostream>
#include<string>

using namespace std;

bool checkPalindrome(string &str, int i){

    int len = str.length();
    // Base Case
    if(i > len/2)
        return true; 
    // Process
    if(str[i] == str[len-i-1])
        return checkPalindrome(str, i+1);
    else 
        return false;

}

int main(){

    string str = "naman";

    if(checkPalindrome(str, 0))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}