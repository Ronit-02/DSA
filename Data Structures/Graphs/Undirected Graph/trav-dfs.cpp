#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Recursive Approach
// Time complexity: O(n) + O(2e)
// Space complexity: O(n)
void dfs(vector<int> adj[], vector<int> &vis, int node, vector<int> &seq){

    // 1. mark and add it
    vis[node] = 1;
    seq.push_back(node);

    // 2. visit adjacent nodes
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]) 
            dfs(adj, vis, adjNode, seq);
    }
}

int main(){

    // assumption: Graph(1 - n)
    int n, e;    
    cin >> n >> e;
    
    // initialize list
    vector<int> adj[100];
    for(int i=1; i<=e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // visited array
    vector<int> vis(n+1, 0);
    vector<int> seq;

    // for disconnected graph, consider all nodes
    for(int node=1; node <= n; node++){
        if(!vis[node]) 
            dfs(adj, vis, node, seq);
    }   

    // dfs sequence
    for(auto x: seq){
        cout << x << " ";
    }

    return 0;
}