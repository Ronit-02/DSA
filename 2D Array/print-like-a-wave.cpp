#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    
    // Time Complexity: O(n+m)
    int i = 0;   // For Traversing Rows
    int j = 0;   // For Traversing Columns
    while(j < mCols){
        
        ans.push_back(arr[i][j]);
        if(j % 2 == 0)   // for even columns -> row value is increasing
            i++;
        else        // for odd values -> row value is decreasing
            i--;
        
        if(i == nRows){
            j++;
            i--;
        }
        if(i == -1){
            j++;
            i++;
        }
    }    
    
//     // Time Complexity: O(n*m)
//     int j = 0;
//     while(j < nCols){
//         if(j % 2 == 0)   // even column
//             while(i < nRows){
//                 ans.push_back(arr[i][j]);
//                 i++;
//             }
//         else        // odd column
//           while(i >= 0){
//                 ans.push_back(arr[i][j]);
//                 i--;
//             }  
        
//         j++;       // updating to next column
//     }
    return ans;
}

int main(){

    vector <vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    int nRows = arr.size();
    int nCols = arr[0].size();

    vector<int> ans;
    ans = wavePrint(arr, nRows, nCols);
     
    return 0;
}