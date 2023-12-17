#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Run length encoding for string compression
//if compressed string is bigger than original return original string
//input: aaabbbcc
//output: a3b3c2

//input: abcd
//output: abcd

string compressString(string str){

    int n = str.length();

    string output;      //output string
    for(int i=0; str[i]!='\0'; i++){

        int count = 1;

        while(i<n-1 && str[i]==str[i+1]){
            count++;
            i++;
        }
        output += str[i];
        output += to_string(count);
    }
    if(str.length() < output.length())
        return str;
    
    return output;
}

int main(){

    string str;
    getline(cin,str);

    string output = compressString(str);

    cout<<"New string is: "<<output;

    return 0;
}