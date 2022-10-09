#include<iostream>
#include<vector>

using namespace std;

// Intuition: 
// we start from somewhere and if we reach a node that is previously visited that
// indicates that graph has a cycle (for that we carry the parent)
bool dfs(vector<int> &vis, vector<int> adj[], int node, int parent){

    vis[node] = 1;  // mark it

    // traversing all adjacent items
    for(auto adjNode: adj[node]){

        // 1. not visited, visit it
        if(vis[adjNode] == 0){
            if(dfs(vis, adj, adjNode, node) == true)  // if detected a cycle, break out
                return true;
        }

        // 2. visited but not parent, cycle
        else if(adjNode != parent){
            return true;
        }
    }   
    return false;
}

bool isCycle(int n, vector<int> adj[]){

    vector<int> vis(n, 0); // visited array

    // for multi-component graph, need to check every node
    for(int i=0; i<n; i++){
        if(!vis[i])
            if(dfs(vis, adj, i, -1))
                return true;
    }
    return false;
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

    // check if cycle
    cout << isCycle(n, adj);

    return 0;
}