#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
  
        // Sliding Window Approach
        // Untill duplicate elements we keep on adding and increase our window size
        // hash set -> to keep check for unique elements
        // ans -> storing the maximum sum till now
        // currSum -> storing current sum of the window
        
        unordered_set<int> hashset;
        
        unsigned int ans = 0;
        unsigned int currSum = 0;
        
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            
            if(hashset.find(nums[j]) == hashset.end()){   // if element not present -> add it
                hashset.insert(nums[j]);
                currSum += nums[j];
                j++;
            }
            else{                     // if element present -> delete first element from window
                // cout<< "Deleted";
                currSum -= nums[i];
                hashset.erase(nums[i]);
                i++;
            }
            
            ans = max(ans, currSum);       
        }
        
        return ans;
    }
};

int main(){

    Solution s;

    vector<int> arr = {4,2,4,5,6};

    int output = s.maximumUniqueSubarray(arr);
    cout<<output;
     
    return 0;
}