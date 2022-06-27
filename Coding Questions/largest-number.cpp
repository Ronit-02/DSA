#include<iostream>
#include<vector>
#include<limits.h>
#include<string>

using namespace std;

class Solution {
public:
    
    bool compare(int x, int y){
        
        string one = to_string(x) + to_string(y);
        string two = to_string(y) + to_string(x);

        int i=0;
        while(i < one.length()){ 
            
            if(one[i] > two[i])
                return true;
            else if(one[i] < two[i])
                return false;       
            i++;                       // if equal, continue to check
        }

        return true;
    }
    
    string largestNumber(vector<int>& nums) {

        if(nums[0] == 0 && nums.size() == 1)
            return "0";
        
        int n = nums.size();
        
        for(int i=0; i < n-1; i++){
            
            for(int j=i+1; j < n; j++){
                
                if(compare(nums[i], nums[j]) == false){
                    
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    
        string ans = "";
        int i = 0;
        
        while(nums[i] == 0 && i < nums.size()) i++;
        
        if(i == nums.size())
            ans = "0";
        else
            while(i < nums.size()){
                ans += to_string(nums[i]);
                i++;
            }

        return ans;
    }  
};

int main(){

    vector<int>arr = {0,0};

    Solution s;
    string output = s.largestNumber(arr);
    cout<<output;
     
    return 0;
}