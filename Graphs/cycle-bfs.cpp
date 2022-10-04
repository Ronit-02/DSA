#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool detectCycle(int n, int e, vector<int> adj[]){

    vector<int> vis(n, 0);
    
    queue<pair<int,int>> q;
    q.push({1, -1});   // assuming starting node as 1

    while(!q.empty()){

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            // case 1: node not visited, add in queue
            if(vis[node] == 0){

            }
            // case 2: node visited, but parent
            if(vis[node] == 1 && it != parent)
            // case 3: node visite, not parent
        }
    }
}

int main(){

    int n, e;
    cin >> n >> e;    

    vector<int> adj[100];

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << detectCycle(n, e, adj);

    return 0;
}