#include<iostream>
#include<vector>

using namespace std;

// Intuition:
// use inclusion exclusion principle

// TC: O(2^n)

void recurSubseq(string str, int index, string substr, vector<string> &ans){
    
    // base case
    if(index == str.length()){
        if(substr != "") 
            ans.push_back(substr);
        return;
    }

    // include
    recurSubseq(str, index+1, substr + str[index], ans);
    
    // exclude
    recurSubseq(str, index+1, substr, ans);
}

int main(){

    string str = "abc";

    vector<string> ans;
    recurSubseq(str, 0, "", ans);

    for(auto it: ans)
        cout << it << endl;

    return 0;
}
