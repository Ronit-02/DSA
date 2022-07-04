#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int A, vector<vector<int>> m, vector<vector<int>> a, int newx, int newy){
    
    int x=newx;
    int y=newy;
    if(a[newx][newy] == 1 || m[newx][newy] == 1 || x < 0 || x > A-1 || y < 0 || y > A-1 )
        return false;
        
    return true;
}

void recurPath(int A, vector<vector<int>> &m, vector<vector<int>> a, int x, int y, int &ans){
    
    if(x == A-1 && y == A-1){
        ans++;
        return;
    }
    
    a[x][y] = 1;  
    
    // right
    int newx = x;
    int newy = y+1;
    if(isSafe(A, m, a, newx, newy)){
        recurPath(A, m, a, newx, newy, ans);
    }
    
    // down
    newx = x+1;
    newy = y;
    if(isSafe(A, m, a, newx, newy)){
        recurPath(A, m, a, newx, newy, ans);
    }
    
    a[x][y] = 0;
    
}

int solve(int A, int B) {
    
    vector<vector<int>> m(A, vector<int> (A, 0));
    
    int x = A/2, y = A/2;  // center coordinates
    
    for(int i=0; i<A; i++){
        for(int j=0; j<A; j++){
            
            int val = abs(i-x) + abs(j-y);
            if(val <= B){
                m[i][j] = 1;
            }
            else
                m[i][j] = 0;
        }
    }
    
    for(int i=0; i<A; i++){
        for(int j=0; j<A; j++){
            cout << m[i][j] <<" ";
        }
        cout << endl;
    }

    vector<vector<int>> a = m;
    
    x = 0;  // row
    y = 0;  // col
    int ans = 0;
    recurPath(A, m, a, x, y, ans);
    
    return ans;
}

int main(){

    int ans = solve(5, 1);

    cout << ans;

    return 0;
}