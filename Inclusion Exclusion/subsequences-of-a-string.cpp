#include<iostream>
#include<vector>

using namespace std;

void recurSubseq(string str, int index, string substr, vector<string> &ans){
    
    // base case
    if(index == str.length()){
        if(substr != "")
            ans.push_back(substr);
        return;
    }
    // exclude
    recurSubseq(str, index+1, substr, ans);
    // include
    substr += str[index];
    recurSubseq(str, index+1, substr, ans);
}

vector<string> subsequences(string str){
    
    vector<string> ans;
    string substr = "";
    
    int index = 0;
    recurSubseq(str, index, substr, ans);
    
    return ans;
}

int main(){

    string str = "abc";

    vector<string> output;
    output = subsequences(str);
    for(auto i: output){
        cout << i <<" ";
    }

    return 0;
}
