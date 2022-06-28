#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> changeBits(int N) {
        
        vector<int> ans;
        
        int x, y = 0;
        x = N;
        
        while(x != 0){
            x = x >> 1;    // right shifting
            y = y << 1 | 1;   // left shifting or 1
        }
        
        ans.push_back(y-N);
        ans.push_back(y);
        
        return ans;
    }
};

int main(){

    int n = 8;

    Solution s;
    vector<int> output = s.changeBits(n);
    
    for(auto x:output)
        cout << x << " ";

    return 0;
}