#include<iostream>
#include<vector>

using namespace std;

// Intuition: 
// we start from somewhere and if we reach a node that is previously visited
// and path visited as well, then it's a cycle

// Time Complexity: O(V+E)
bool dfs(vector<int> &vis, vector<int> &path, vector<int> adj[], int node){

    vis[node] = 1;  // mark it
    path[node] = 1;

    // traversing all adjacent items
    for(auto adjNode: adj[node]){

        // 1. not visited, visit it
        if(vis[adjNode] == 0){
            if(dfs(vis, path, adj, adjNode) == true)    // if detected a cycle, break out
                return true;
        }

        // 2. visited but in same path
        else if(path[adjNode] == 1){
            return true;
        }
    }   
    path[node] = 0;  // unmark it
    return false;
}

bool isCycle(int n, vector<int> adj[]){

    vector<int> vis(n, 0); // visited array
    vector<int> path(n, 0);  // path-visited array

    // for multi-component graph, need to check every node
    for(int i=0; i<n; i++){
        if(!vis[i])
            if(dfs(vis, path, adj, i))
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
    }

    // check if cycle
    cout << isCycle(n, adj);

    return 0;
}