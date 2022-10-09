#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition: (Kahn's Algorithm)
// node with indegree(=0) are placed before others
vector<int> topoSort(int n, vector<int> adj[]){

    // 1. calculate indegree's (incoming edges)
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto adjNode: adj[i])
            indegree[adjNode]++;
    }

    // 2. push node with indegree (=0)
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // 3. bfs approach
    vector<int> topo;
    while(!q.empty()){

        int node = q.front();
        q.pop();
        topo.push_back(node);

        // remove indegree of node which is in topo sort 
        for(auto adjNode: adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0)
                q.push(adjNode);
        }
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