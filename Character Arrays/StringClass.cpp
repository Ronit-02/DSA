#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string str;     //dynamic array

    getline(cin,str,'.');
    cout<< str;

    //taking multiple string input
    int n = 5;
    vector <string> sarr;
    string temp;

    while(n--){

        getline(cin, temp);
        sarr.push_back(temp);
    }

    for(string x:sarr){
        cout<< x <<", ";
    }

    return 0;
}