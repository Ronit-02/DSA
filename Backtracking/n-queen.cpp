#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool isSafe(int n, int row, int col, vector<vector<int>> board){
    
        // Same Row
        for(int i=0; i<n; i++){
            if(board[row][i] == 1)
                return false;
        }
        // Primary Diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 1)
                return false;
        }
        // Secondary Diagonal
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--){
            if(board[i][j] == 1)
                return false;
        }
        return true;
    }
    void recurnQueen(int n, int col, vector<int> comb, vector<vector<int>> &board, vector<vector<int>> &ans){
        
        // base case
        if(col == n){
            ans.push_back(comb);
            return;
        }
        
        for(int row = 0; row < n; row++){      
            if(isSafe(n, row, col, board)){
                
                board[row][col] = 1;     // Add
                comb.push_back(row+1);

                recurnQueen(n, col+1, comb, board, ans);   // Recur
 
                board[row][col] = 0;      // Backtrak
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> ans;
        vector<int> comb;
        vector<vector<int>> board( n , vector<int> (n));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board[i][j] = 0;

        int col = 0;
        recurnQueen(n, col, comb, board, ans);
        
        return ans;
    }
};

int main(){

    Solution s;

    int n = 4;
    vector<vector<int>> ans = s.nQueen(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << ans[i][j] <<" ";
        cout << endl;
    }
        

    return 0;
}