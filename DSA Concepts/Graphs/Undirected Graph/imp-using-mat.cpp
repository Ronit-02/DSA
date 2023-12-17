#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(e)
// Space Complexity: O(n*n)
int main(){

    int n;  // no of nodes
    int e;  // no of edges
    cin >> n >> e;  

    // 2d array of [n+1]*[e+1], as we are taking 1-based indexing
    // 1. using pointer
    int **a = new int*[n+1];

    for(int i=1; i<=n; i++){
        a[i] = new int[e+1];
    }

    // 2. using vector
    vector<vector<int>> adj(n+1, vector<int>(e+1, 0));

    // for all the edges...
    for(int i=0; i<e ;i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}