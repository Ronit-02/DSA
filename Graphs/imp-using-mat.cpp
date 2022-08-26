#include<iostream>
#include <vector>

using namespace std;

// Space Complexity: O(n*n)
int main(){

    int n;  // no of nodes
    int m;  // no of edges
    cin >> n >> m;  

    // Through vector (normal fill or resize or push_back)
    vector<vector<int>> a(n, vector<int>(m, 0));
    
    // Through pointers
    int **adj = new int*[n];
    for(int i=0; i<n; i++){
        adj[i] = new int[m];
    }

    return 0;
}