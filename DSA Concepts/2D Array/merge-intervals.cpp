#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:
// Merge all overlapping intervals

// Time complexity: O(nlogn)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
     
    vector<vector<int>> mergedIntervals;

    // sort - O(nlogn)
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];

    // overlap intervals - O(n)
    for(auto intv: intervals){
        if(intv[0] <= tempInterval[1]){
            tempInterval[1] = max(intv[1], tempInterval[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            tempInterval = intv;
        }
    }
    mergedIntervals.push_back(tempInterval);
    
    return mergedIntervals;
}

int main(){
    
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> res = merge(intervals);
    for(auto intv: res){
        for(auto i: intv)
            cout << i << ",";
        cout << endl;
    }

    return 0;
}