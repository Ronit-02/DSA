#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition: (Brute Force)
// We will color all the adjacent (non-visited) nodes with compliment
// color and if any visited node has contradictory color, its not bipartite
bool bfs(vector<int> &color, vector<int> adj[], int src){
    
    color[src] = 0;   // color it

    queue<int> q;
    q.push(src);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for(auto adjNode: adj[node]){
            // 1. not colored -> color, add in queue
            if(color[adjNode] == -1){
                color[adjNode] = !color[node];
                q.push(adjNode);
            }
            // 2. colored and has same color
            else if(color[adjNode] == color[node]){
                return false;
            }
        }
    }
    return true;
}

// TC: O(n + 2e)
// SC: O(n)
bool isBipartite(int n, int e, vector<int> adj[]){

    vector<int> color(n, -1); // color array

    // for multi-component graph, need to check every node
    for(int i=0; i<n; i++){
        if(color[i] == -1)
            if(bfs(color, adj, i) == false)
                return false;
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