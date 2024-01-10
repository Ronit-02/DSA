#include<iostream>
#include<limits.h>
#include<vector>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n+1,0);
        vector <int> ans;
        for(int i: nums)
        {
                res[i]++;
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==2)
            {
                ans.push_back(i);
            }
            
        }
        return ans; 
    }
};

int main(){

    vector<int> vec = {4,3,2,7,8,2,3,1};

    Solution s;
    s.findDuplicates(vec);
    // cout<<output;
     
    return 0;
}