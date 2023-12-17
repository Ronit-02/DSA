#include<iostream>
#include<string>

using namespace std;

void stringReverse(string &str, int i){

    int len = str.length();
    // Base Case
    if(i > len/2)
        return;
    // Process
    swap(str[i], str[len-i-1]);
    //Recursive Call
    stringReverse(str, i+1);

}

int main(){

    string str = "ronit";

    stringReverse(str, 0);
    cout << endl << str;

    return 0;
}