#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// TC: O(V + 2E)
// Intuition:
// BFS travels one by one to adjacent nodes, it will
// help when edges are unweighed or have unit weight
vector<int> shortestPath(int n, int e, vector<int> adj[]){

    // Modified BFS
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    q.push(0);  // starting node 0
    dist[0] = 0;

    while(!q.empty()){

        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[it] + 1 < dist[it]){
                dist[it]++;
                q.push(it);    
            }
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
        adj[v].push_back(u);  
    }

    vector<int> path;
    path = shortestPath(n, e, adj);
    for(auto x: path)
        cout << x << " ";

    return 0;
}