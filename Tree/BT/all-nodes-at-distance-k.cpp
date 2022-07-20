#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

struct node{
public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int data){
        
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Using level order traversal as i/p
void buildTree(node* &root){

    // using queue to store left and right nodes
    queue<node *> q;

    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        // root -> left data
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left); 
        }

        // root -> right data
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right); 
        }
    }
}

// Iterative bfs apporach
node *createMapping(node* root, unordered_map <node*, node*> &nodeParent, int t){
    
    node *target = NULL;
    queue <node*> q;
    q.push(root);
    
    nodeParent[root] = NULL; 
    
    while(!q.empty()){
        
        node *curr = q.front();
        q.pop();

        if(curr -> data == t)
            target = curr;
        
        if(curr -> left){
            nodeParent[curr -> left] = curr;
            q.push(curr -> left);
        }
        if(curr -> right){
            nodeParent[curr -> right] = curr;
            q.push(curr -> right);
        }
    }

    return target;
}

// Recursive Approach
void helper(node* node, int distance, int k, vector<int> &ans, 
            unordered_map <node *, node *> nodeParent, unordered_map <node*, int> &visited){
    
    // base case
    if(node == NULL){
        return;
    }
    
    // ans case
    if(distance > k)
        return;
    if(distance == k){
        
        // if visited
        if(visited.find(node) != visited.end()){
            return;
        }
        else{
            visited[node] = 1;
            ans.push_back(node -> data);
            return;
        }
    }
    
    // left, right, root
    helper(node -> left, distance+1, k, ans, nodeParent, visited);
    helper(node -> right, distance+1, k, ans, nodeParent, visited);
    helper(nodeParent[node], distance+1, k, ans, nodeParent, visited);
}

vector<int> distanceK(node* root, int t, int k) {
    
    // step 1: mapping for node to parent
    unordered_map <node*, node*> nodeParent;
    createMapping(root, nodeParent, t);
    
    // step 2: using visited map, visit all nodes from target node
    vector <int> ans;
    unordered_map <node*, int> visited;

    node *target = NULL;
    visited[target] = 1;
    helper(target, 0, k, ans, nodeParent, visited);
    
    return ans;
}

int main(){

    node* root = NULL;

    buildTree(root);
    // 0 2 1 -1 -1 3 -1

    int target = 3;
    vector<int> ans = distanceK(root, target, 3);
    for(auto i: ans)
        cout << i << " "; 

    return 0;
}