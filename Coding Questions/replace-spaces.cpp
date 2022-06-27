#include<iostream>
#include<string>
using namespace std;

// Function without using any extra space
// Time Comp: O(n), Space Comp: O(1)
string replaceSpaces(string &str){
	
    for(int i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str = str.substr(0, i) + "@40" + str.substr(i+1, str.length());
    }
    
    return str;
}
int main(){

    return 0;
}