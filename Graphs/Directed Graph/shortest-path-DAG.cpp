#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// TC: O(V + E)
// Intuition:
// Processing the vertices in topological order ensures by the time you get to a vertex,
// you've already processed all the preceding nodes.
void topoSort(vector<int> &vis, stack<int> &st, vector<pair<int,int>> adj[], int node){

    vis[node] = 1;  // mark it

    // traversing all adjacent items not visited
    for(auto adjNode: adj[node]){
        int v = adjNode.first;
        if(!vis[v])
            topoSort(vis, st, adj, v);
    }

    st.push(node);
}

vector<int> shortestPath(int n, int e, vector<int> edge[]){

    // create weighted list
    vector<pair<int,int>> adj[100];  // (edge, weight)
    for(int i=0; i<e; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        adj[u].push_back({v, wt});
    }

    // 1. Topological sort (DFS)
    vector<int> vis(n, 0);
    stack<int> st;

    for(int i=0; i<n; i++){
        if(!vis[i])
            topoSort(vis, st, adj, i);
    }

    // 2. Take nodes out of stack & relax the edges
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;   // assuming 0 as source node(top of stack)

    while(!st.empty()){

        int node = st.top();
        st.pop();
        for(auto adjNode: adj[node]){
            int v = adjNode.first;
            int wt = adjNode.second;
            dist[v] = min(dist[v], dist[node]+wt);
        }
    }
    return dist;
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

    vector<int> path;
    path = shortestPath(n, e, adj);
    for(auto x: path)
        cout << x << " ";

    return 0;
}