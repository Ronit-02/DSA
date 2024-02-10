#include<iostream>
#include<string>

using namespace std;

void stringReverse(int i, string &str){

    int len = str.length();

    // Base Case
    if(i > len/2)
        return;
    
    // Swap
    swap(str[i], str[len-i-1]);

    //Recursive Call
    stringReverse(i+1, str);
}

int main(){

    string str = "ronit";

    stringReverse(0, str);
    cout << str;

    return 0;
}