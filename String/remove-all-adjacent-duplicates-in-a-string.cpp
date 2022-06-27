#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    int containsDuplicate(string s){    // -1 if it doesnt contains duplicate, otherwise its index
     
        for(int i=0; i<s.length() - 1; i++)
            if(s[i] == s[i+1])
                return i;
        
        return -1;
    }
    string removeDuplicates(string s) {
        
        while(s.length() > 0){
            
            int i = containsDuplicate(s);
            
            if(i != -1)         // duplicates present
                s.erase(i, 2);
            else                // no more duplicates present
                break;
        } 
        return s;
    }
};

int main(){

    Solution s;
    string str = "aaaaaafbbbsc";

    string output = s.removeDuplicates(str);
    cout<<output;
     
    return 0;
}