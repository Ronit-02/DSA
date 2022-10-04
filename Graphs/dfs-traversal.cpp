#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Recursive Approach
void dfs(vector<int> &vis, vector<int> &trav, vector<int> adj[], int node){

    vis[node] = 1;
    trav.push_back(node);

    for(auto adjNode: adj[node]){
        if(vis[adjNode] != 1) 
            dfs(vis, trav, adj, adjNode);
    }
}

// Time complexity: O(n) + O(2e)
// Space complexity: O(n)
vector<int> DFS(int n, int e, vector<int> adj[]){

    // visited array
    vector<int> vis(n, 0);
    // to store traversal
    vector<int> trav;

    // starting node (taking it to be 1 in this case)
    int start = 1; 

    dfs(vis, trav, adj, start);
    return trav;
}

int main(){

    int n, e;    
    cin >> n >> e;
    
    vector<int> adj[100];
    
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> trav = DFS(n, e, adj);

    for(auto x: trav){
        cout << x << " ";
    }

    return 0;
}