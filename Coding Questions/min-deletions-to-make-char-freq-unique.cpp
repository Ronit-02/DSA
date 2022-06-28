#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        
        int ans = 0;
        int n = s.length();
        
        // count frequencies of each character
        unordered_map<char ,int> freq;
        for(int i=0; i<n; i++)
            freq[s[i]]++;
        
        // we'll maintain a set for freq we have encountered
        unordered_set<int> visited;
        for(auto[k, v] : freq){
            
            // while we encounter same freq -> decrement
            while(visited.find(v) != visited.end()){    
                v--;
                ans++;
            }
            // otherwise -> add it in set
            if(v > 0)
                visited.insert(v);
        }
        return ans;
    }
};

int main(){

    Solution s;

    int output = s.minDeletions("aabbbcc");
    cout << output;
     
    return 0;
}