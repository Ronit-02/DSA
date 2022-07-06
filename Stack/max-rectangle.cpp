#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void nextSmaller(vector<int> arr, vector<int> &next, int n){
    
    stack<int> s;
    s.push(-1);
    
    for(int i=n-1; i>=0; i--){
        
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        
        next[i] = s.top();
        s.push(i);   // pushing index
    }
}
void prevSmaller(vector<int> arr, vector<int> &prev, int n){
    
    stack<int> s;
    s.push(-1);
    
    for(int i=0; i<n; i++){
        
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        
        prev[i] = s.top();  
        s.push(i);   // pushing index 
    }
}
int calculateMaxArea(vector<int> row){
    
    int n = row.size();
    int ans = 0;
    
    vector<int> next(n);    // to store next smaller element index
    nextSmaller(row, next, n);
        
    vector<int> prev(n);   // to store prev smaller element index
    prevSmaller(row, prev, n);
    
    for(int i=0; i<n; i++){
        
        int l = row[i];
        
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        
        ans = max(ans, l*b);
    }
    return ans;
}
int maximalRectangle(vector<vector<int>>& matrix) {
    
    int ans = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    
    for(int i=0; i<m; i++){
        
        // 1. making row after adding above rows data
        
        vector<int> row;
        
        for(int j=0; j<n; j++){
            
            int temp = 0;
            for(int k=i; k>=0; k--){
                
                if(matrix[i][j] == 0)     // should contain zero value
                    break;
                if(matrix[k][j] == 0)
                        break;
                temp += matrix[k][j];
            }
            row.push_back(temp);
        }

        cout << "Row elements: " << endl;
        for(auto i :  row){
            cout << i << " ";
        }
        cout << endl;
        // 2. calculate max area of that row
        int newArea = calculateMaxArea(row);

        cout << "New area = " << newArea << endl;
        
        ans = max(ans, newArea);
    }
    
    return ans;
}

int main(){

    vector<vector<int>> 
    matrix = {{1,0,1,1,1},
            {0,1,0,1,0},
            {1,1,0,1,1},
            {1,1,0,1,1},
            {0,1,1,1,1}};

    int ans = maximalRectangle(matrix);
    cout << ans;

    return 0;
}