#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Intuition:
// saving terminal nodes (reverse, indegree=0) and others which have
// linear dependency on terminal nodes using Kahn's Alogrithm
vector<int> safeStates(int n, vector<int> adj[]){

    vector<int> safe;
    vector<int> adjRev[100];  // reverse adjacency list

    // 1. calculate indegree
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto adjNode: adj[i]){
            adjRev[adjNode].push_back(i);
            indegree[i]++;
        }
    }

    // 2. terminal nodes with indegree(=0)
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // 3. bfs approach
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safe.push_back(node);

        // node in topo sort has to removed from indegree
        for(auto adjNode: adjRev[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) 
                q.push(adjNode);
        }
    }

    sort(safe.begin(), safe.end());
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