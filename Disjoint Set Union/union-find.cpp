#include<iostream>
using namespace std;

int parent[1000];

// initialization
void makeSet(int n) {

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}

// Find parent
// TC: O(log n)
int findParent(int node) {

    if(node == parent[node])
        return node;
    
    return findParent(parent[node]);
}

// Union
void Union(int u, int v) {

    int x = findParent(u);
    int y = findParent(v);

    if(x == y) 
        return;

    parent[y] = x;
}

int main() {

    int m;
    cin >> m;
    makeSet(m);

    while(m--){
        int u,v;
        cin >> u >> v;
        Union(u, v);   // make friends
    }

    // find if 2 and 3 be belong to same component or not
    if(findParent(2) != findParent(3))
        cout << "Different components";
    else
        cout << "Same components";

    return 0;
}