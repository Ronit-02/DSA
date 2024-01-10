#include<iostream>
#include<vector>

using namespace std;

// Intuition: (detect cycle)
// all the nodes which are part of a cycle or lead to a cycle 
// are not safe nodes, rest are!
bool dfs(vector<int> &vis, vector<int> &path, vector<int> adj[], int node){

    vis[node] = 1;  // mark it
    path[node] = 1;

    // traversing all adjacent items
    for(auto adjNode: adj[node]){

        // 1. not visited, visit it
        if(vis[adjNode] == 0){
            if(dfs(vis, path, adj, adjNode) == true)  // if detected a cycle, break out
                return true;
        }

        // 2. visited but in same path
        else if(path[adjNode] == 1){
            return true;
        }
    }
    path[node] = 0;   
    return false;
}

vector<int> safeStates(int n, vector<int> adj[]){

    vector<int> vis(n, 0); // visited array
    vector<int> path(n, 0);  // path-visited array

    // need to check every node if it leads to a cycle or not
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(vis, path, adj, i);
    }

    vector<int> safe;

    // all marked as path = 0, are safe
    for(int i=0; i<n; i++){
        if(path[i] == 0)
            safe.push_back(i);
    }
    return safe;
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

    vector<int> safe;
    safe = safeStates(n, adj);
    for(auto x: safe)
        cout << x << " ";

    return 0;
}