#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity: O(n) + O(2e)
vector<int> bfs(int n, vector<int> adj[]){

    vector<int> bfs;
    vector<int> vis(n, 0);  // visited array
    vis[0] = 1;

    queue<int> q;
    q.push(0);   // assuming, starting node = 0

    while(!q.empty()){
        int node = q.front();
        q.pop();

        // visit all neighbours which are not visited
        // 1. mark it visited
        // 2. push in queue
        for(auto adjNode: adj[node]){
            if(vis[adjNode] == 0){
                vis[adjNode] = 1;  // mark
                q.push(adjNode);   // push
            }
        }

        // adding in the array
        bfs.push_back(node);
    }
    return bfs;
}

int main(){

    int n, e;    
    cin >> n >> e;
    
    // initialize adjacency list
    vector<int> adj[100];
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS Traversal
    vector<int> trav = bfs(n, adj);
    for(auto x: trav){
        cout << x << " ";
    }

    return 0;
}