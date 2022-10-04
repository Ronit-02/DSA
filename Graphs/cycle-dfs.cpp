#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<int> &vis, vector<int> adj[], int node, int parent){

    vis[node] = 1;

    // traversing all adjacent items
    for(auto adjNode:  adj[node]){

        // if not visited
        if(vis[adjNode] == 0){
            if(dfs(vis, adj, adjNode, node == true))
                return true;
        }

        // if visited and not parent
        else if(adjNode != parent){
            return true;
        }
    }   

    return false;
}

bool isCycle(int n, int e, vector<int> adj[]){

    // visited array
    vector<int> vis(n, 0);

    // for multi-component graph
    for(int i=0; i<n; i++){
        if(!vis[i])
            if(dfs(vis, adj, i, -1) == true)
                return true;    
    }

    return false;
}

int main(){

    int n, e;
    cin >> n >> e;    

    vector<int> adj[100];

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isCycle(n, e, adj);

    return 0;
}