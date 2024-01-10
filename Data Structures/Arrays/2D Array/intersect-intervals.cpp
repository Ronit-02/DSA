#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:
// Intersect all overlapping intervals 

// Intuition: 2 pointer approach
// Time complexity: O(nlogn)
vector<vector<int>> intersect(vector<vector<int>>& a, 
vector<vector<int>>& b){     

    vector<vector<int>> res;

    // 2 pointers
    int i = 0, j = 0;
    vector<int> temp = {0,0};
    
    while(i < a.size() && j < b.size()){

        // check for intersection
        if(a[i][0] <= b[j][1] && a[i][1] >= b[j][0]){
            temp[0] = max(a[i][0], b[j][0]);
            temp[1] = min(a[i][1], b[j][1]);
            res.push_back(temp);
        }
        // update poiters
        if(a[i][1] > b[j][1])
            j++;
        else 
            i++;
    }

    return res;
}

int main(){
    
    vector<vector<int>> a = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> b = {{1,5},{8,12},{15,24},{25,29}};

    vector<vector<int>> res = intersect(a, b);
    for(auto intv: res){
        for(auto i: intv)
            cout << i << ",";
        cout << endl;
    }

    return 0;
}