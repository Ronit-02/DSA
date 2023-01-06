#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<int> adj[], vector<int> &vis, int node, vector<int> seq, vector<int> &path){

        vis[node] = 1;
        seq.push_back(node);

        for(auto x: seq)
            cout << x;
        cout << endl;

        if(node == 0){
            path = seq;
            return;
        }
    
        for(auto adjNode: adj[node]){
            if(!vis[adjNode])
                dfs(adj, vis, adjNode, seq, path);
        }
    }

int main(){

    vector<vector<int>> edges = {{0,2},{1,4},{1,6},{2,4},{3,6},{3,7},{5,7}};
    int bob = 4;
    vector<int> amount = {-6896,-1216,-1208,-1108,1606,-7704,-9212,-8258};

    int n = 8;
    vector<int> adj[8];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // track bob path
    vector<int> vis(n, 0);
    vector<int> seq, path;
    dfs(adj, vis, bob, seq, path);


    return 0;
}