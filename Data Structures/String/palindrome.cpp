#include <iostream>
#include <string.h>

using namespace std;

bool isPalindrome(string str){      //string str    dynamic array

    int len = str.length();

    for(int i=0; i<len/2; i++){

        if(str[i] != str[len-i-1])
            return false;
    }

    return true;
}

int main(){

    char string[1000];

    cin.getline(string, 1000);

    cout<<isPalindrome(string);

    return 0;
}