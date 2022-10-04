#include<iostream>
using namespace std;

int parent[1000];
int ranks[1000];

// initialization
void makeSet(int n) {

    for(int i=1; i<=n; i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}

// Find parent with "Path compression"
// TC: O(4*alpha) = O(1)
int findParent(int node) {

    if(node == parent[node])
        return node;
    
    return parent[node] = findParent(parent[node]);
}

// Union - Rank based
void Union(int u, int v) {

    int x = findParent(u);
    int y = findParent(v);

    if(ranks[x] < ranks[y])
        parent[x] = y;
    else if(ranks[x] > ranks[y])
        parent[y] = x;
    else {
        parent[y] = x;
        ranks[x]++;
    }
}

int main() {

    int m;
    cin >> m;
    makeSet(m);

    while(m--){
        int u,v;
        cin >> u >> v;
        Union(u, v);
    }

    // find if, 2 and 3 belong to same component or not
    if(findParent(2) != findParent(3))
        cout << "Different components";
    else
        cout << "Same components";

    return 0;
}