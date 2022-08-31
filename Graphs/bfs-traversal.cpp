#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity: O(n) + O(2e)
vector<int> BFS(int n, int e, vector<int> adj[]){

    vector<int> vis(n, 0);  // visited array
    vis[0] = 1;

    queue<int> q;
    q.push(0);   // assuming, starting node = 0

    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }

        bfs.push_back(node);
    }
    return bfs;
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

    vector<int> trav = BFS(n, e, adj);

    for(auto x: trav){
        cout << x << " ";
    }

    return 0;
}