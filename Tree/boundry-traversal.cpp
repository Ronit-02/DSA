#include<iostream>
#include<stack>
#include<vector>
#include<queue>

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

void preorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

class Solution {
public:
    void inorderTrav(node* root, vector<int> &ans){
        
        // base case
        if(root == NULL)
            return;
        // adding leaf node
        if(root -> left == NULL && root -> right == NULL){  
            ans.push_back(root -> data);
            return;
        }
            
        // left
        inorderTrav(root->left, ans);
        // right
        inorderTrav(root->right, ans);
    }
    
    void leftTrav(node* root, vector<int> &ans){
        
        // leaf node
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        
        // adding before calling
        ans.push_back(root -> data);
        
        if(root -> left)
            leftTrav(root->left, ans);
        else
            leftTrav(root->right, ans);
    }
    
    void rightTrav(node* root, vector<int> &ans){
        
        // leaf node
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
            
        if(root -> left)
            rightTrav(root->left, ans);
        else
            rightTrav(root->right, ans);
            
        // adding before returning
        ans.push_back(root -> data);
    }
    
    vector <int> boundary(node *root)
    {
        vector<int> ans;
        if(root == NULL){
            ans.push_back(root->data);
            return ans;
        }
        
        ans.push_back(root->data);
        
        // left part
        leftTrav(root->left, ans);
        
        // all the leaf nodes
        // left subtree
        inorderTrav(root->left, ans);
        // right subtree
        inorderTrav(root->right, ans);
        
        // right part
        rightTrav(root->right, ans);
        
        return ans;
    }
};

int main(){

    node* root = NULL;

    buildTree(root);
    // 4 10 -1 5 5 -1 6 7 -1 8 8 -1 8 11 -1 3 4 -1 1 3 -1 8 6 -1 11 11 -1 5 8

    cout << "Printing Preorder Traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    Solution s;
    vector<int> ans;

    cout << "Boundary Traversal: " << endl;
    ans = s.boundary(root);
    for(auto i: ans){
        cout << i << " "; 
    }

    return 0;
}