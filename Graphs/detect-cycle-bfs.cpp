#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition:
// starting from 2 different paths and colliding at some place, then 
// that will only be because of cycle (pass parent as pair)
bool bfs(vector<int> &vis, vector<int> adj[], int src){
    
    vis[src] = 1;   // mark it
    queue<pair<int,int>> q;  // (node, parent)
    q.push({src, -1}); 

    while(!q.empty()){

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode: adj[node]){
            // 1. not visited, visit and add in queue
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            // 2. node visited and is not parent
            else if(adjNode != parent){
                return true;
            }
        }
    }
    return false;
}

// TC: O(n + 2e)
// SC: O(n)
bool isCycle(int n, int e, vector<int> adj[]){

    vector<int> vis(n, 0); // visited array

    // for multi-component graph, need to check every node
    for(int i=0; i<n; i++){
        if(!vis[i])
            if(bfs(vis, adj, i))
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

    // for multisource
    cout << isCycle(n, e, adj);
    return 0;
}