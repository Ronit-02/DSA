#include <iostream>
#include <vector>

using namespace std;

// Intuition:
// Add element, recursively call for next index
// remove and backtrack after exploring depth

// TC: O(2^n * n)

void subsets(vector<int> nums, int index, vector<vector<int>> &ans, vector<int> curr){

    ans.push_back(curr);

    for(int i=index; i<nums.size(); i++){
        // add
        curr.push_back(nums[i]);
        // recur
        subsets(nums, i+1, ans, curr);
        // remove
        curr.pop_back();
    }
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> curr;

    subsets(nums, 0, ans, curr);

    for(auto &it: ans){
        for(auto &at: it){
            cout << at;
        }
        cout << endl;
    }

    return 0;
}