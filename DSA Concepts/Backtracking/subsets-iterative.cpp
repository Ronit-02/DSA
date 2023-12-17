#include <iostream>
#include <vector>

using namespace std;

// Intuition: 
// Iterative approach adding elements one by one
// to existing starting from an empty set
// TC: O(2^n * n)
vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<vector<int>> subsets;
    subsets.push_back({});
    
    for(int i=0; i<nums.size(); i++){
        
        int n = subsets.size();
        for(int j=0; j<n; j++){
            // extract
            vector<int> temp = subsets[j];
            // modify
            temp.push_back(nums[i]);
            // add
            subsets.push_back(temp);
        }
    }
    
    return subsets;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);

    return 0;
}