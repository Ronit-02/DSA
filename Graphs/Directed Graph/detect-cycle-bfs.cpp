#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition: 
// if Topo Sort = N elements, then its a DAG (no cycle)
bool isCycle(int n, vector<int> adj[]){

    // 1. calculate indegree
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto adjNode: adj[i])
            indegree[adjNode]++;
    }

    // 2. push node with indegree(=0)
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

        // node in topo sort has to removed from indegree
        for(auto adjNode: adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) 
                q.push(adjNode);
        }
    }   

    // if topo sort has n elements, no cycle (DAG)
    if(topo.size() == n) return false;
    return true;
}

int main(){

    int n, e;
    cin >> n >> e;

    // Initialize (starting node as 0)
    vector<int> adj[100];
    for(int i=0; i<e; i++){
        int u,v;
        cin >> u >> v;   // u -> v
        adj[u].push_back(v);
    }

    cout << isCycle(n, adj);

    return 0;
}