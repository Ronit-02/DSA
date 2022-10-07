#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Recursive Approach
void dfs(vector<int> &vis, vector<int> &trav, vector<int> adj[], int node){

    // 1. mark and add it
    vis[node] = 1;
    trav.push_back(node);

    // 2. visit adjacent nodes
    for(auto adjNode: adj[node]){
        if(vis[adjNode] != 1) 
            dfs(vis, trav, adj, adjNode);
    }
}

// Time complexity: O(n) + O(2e)
// Space complexity: O(n)
vector<int> DFS(int n, int e, vector<int> adj[]){

    vector<int> vis(n, 0);
    vector<int> trav;  // store trav

    int start = 0;    // starting node
    dfs(vis, trav, adj, start);
    return trav;
}

int main(){

    int n, e;    
    cin >> n >> e;
    
    // Initialize list
    vector<int> adj[100];
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Traversal
    vector<int> trav = DFS(n, e, adj);
    for(auto x: trav){
        cout << x << " ";
    }

    return 0;
}