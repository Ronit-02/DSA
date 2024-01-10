#include<iostream>
#include<vector>

using namespace std;

// Gray code: made from prev bit version
// feature: only 1 bit changes

vector<string> graycode(int n){

    if(n == 1){
        vector<string> code = {"0", "1"};
        return code;
    }

    vector<string> basecode = graycode(n-1);
    vector<string> newcode;
    
    for(int i=0; i<basecode.size(); i++){
        string code = "0" + basecode[i];
        newcode.push_back(code);
    }
    for(int i=basecode.size()-1; i>=0; i--){
        string code = "1" + basecode[i];
        newcode.push_back(code);
    }

    return newcode;
}

int main(){

    int n;
    cin >> n;

    vector<string> code = graycode(n);
    for(auto it: code){
        cout << it << endl;
    }

    return 0;
}