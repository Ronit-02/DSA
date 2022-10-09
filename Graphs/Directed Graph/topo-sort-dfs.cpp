#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Intuition: (Directed Acyclic Graph)
// Process a node after all of its children are processed. 
// Each time a node is processed, it is pushed onto a stack
void dfs(vector<int> &vis, stack<int> &st, vector<int> adj[], int node){

    vis[node] = 1;  // mark it

    // traversing all adjacent items not visited
    for(auto adjNode: adj[node]){
        if(vis[adjNode] == 0)
            dfs(vis, st, adj, adjNode);
    }

    st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[]){

    vector<int> vis(n, 0); // visited array
    stack<int> st;

    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(vis, st, adj, i);
    }

    // storing the result
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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

    vector<int> topo;
    topo = topoSort(n, adj);
    for(auto x: topo)
        cout << x << " ";

    return 0;
}