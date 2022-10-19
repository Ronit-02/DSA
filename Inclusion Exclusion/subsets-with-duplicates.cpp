#include <iostream>
#include <vector>

using namespace std;

// Intuition:
// backtrack and skip duplicates
// TC: 
void helper(vector<int> &nums, int index, vector<int> curr, vector<vector<int>> &ans){

    ans.push_back(curr);

    for(int i=index; i<nums.size(); i++){

        // for duplicate no's -> SKIP
        if(i > index && nums[i-1] == nums[i])
            continue;

        curr.push_back(nums[i]);
        helper(nums, i+1, curr, ans);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> nums){

    vector<vector<int>> ans;
    vector<int> curr;

    helper(nums, 0, curr, ans);    
    return ans;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    ans = subsetsWithDup(nums);

    return 0;
}