#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> mat, int r, int c){

    // row
    int left = 0;
    int right = c-1;
    // col
    int top = 0;
    int bottom = r-1;

    vector<int> ans;

    while(top <= bottom && left <= right){

        // left to right
        for(int i=left; i<=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        // top to bottom
        for(int i=top; i<=bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        // right to left
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // bottom to top
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {

    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int r = 4;
    int c = 4;

    vector<int> res = spiralPrint(mat, r, c);
    for(auto it: res)
        cout << it << " ";

	return 0;
}