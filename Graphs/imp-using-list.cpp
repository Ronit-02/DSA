#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(e)
// Space Complexity: O(2e)
int main(){

    int n;   // nodes 
    int e;   // edges
    cin >> n >> e;

    // array of vectors or adjacency list
    vector<int> adj[100];

    // for all the edges...
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;   
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    return 0;
}