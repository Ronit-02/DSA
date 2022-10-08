#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition:
// As we go coloring nodes with complement color which are not visited
// finding a node which is visited with same color
bool dfs(vector<int> &color, vector<int> adj[], int node){
    
    for(auto adjNode: adj[node]){
        
        // 1. not colored -> opp color, recur
        if(color[adjNode] == -1){
            color[adjNode] = !color[node];
            if(dfs(color, adj, adjNode) == false)
                return false;
        }
        
        // 2. colored and same color
        else if(color[adjNode] == color[node]){
            return false;
        }
    }
    return true;
}

// TC: O(n + 2e)
// SC: O(n)
bool isBipartite(int n, int e, vector<int> adj[]) {
    
    vector<int> color(n, -1);   // color array
    
    // for multi-component graph, need to check every node
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(dfs(color, adj, i) == false)
                return false;
        }
    }
    
    return true;
}

int main(){

    int n, e;
    cin >> n >> e;    

    // Initialize (starting node as 0)
    vector<int> adj[100];
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isBipartite(n, e, adj);
    return 0;
}


class Solution {
public:
    
};