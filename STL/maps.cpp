#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    
    map<int,string> m;   

    // ordered map uses inbuilt tree
    // insertion: map sorts based on key - O(logn)
    m[1] = "abc";
    m[3] = "def";
    m[2] = "f";
    
    // access - O(logn)
    for(auto &pr: m)   
        cout << pr.first << "-" << pr.second << endl; 

    // find: O(logn)
    auto it = m.find(3);
    if(it != m.end()) 
        cout << "Found: " << (*it).first << "-" << (*it).second << endl;
    else    
        cout << "not found";

    // deletion: O(logn)
    m.erase(2);
    
    // insertion time varies
    map<string, string> sm;
    sm["abcd"] = "defs";    // O(s.size() + logn)



    // unordered map uses inbuilt hashing (doesn't sorts)
    // can't use set, vector, pairs as 'key'
    unordered_map<int,string> mp;
    
    // insertion: O(1)
    mp[1] = "rnr";
    mp[4] = "ab";
    mp[2] = "deff";

    for(auto &pr: mp)
        cout << pr.first << "-" << pr.second << endl; 

    return 0;
}