#include<iostream>
#include<stack>

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

node* buildTree(node* root){

    int data;
    // cout << "Enter the data: " << endl;
    cin >> data;

    // null case
    if(data == -1)
        return NULL;

    // root node
    root = new node(data);

    // left node
    // cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    // right node
    // cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

// Recursive Method
void preorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

// Iterative method using Stack
void preorderTrav(node* root){

    stack<node *> s;

    // push root in stack
    s.push(root);

    while(!s.empty()){

        // pop root, print it
        node *temp = s.top();
        s.pop();
        cout << temp -> data << " ";

        // push root->right and root->left
        if(temp -> right){
            s.push(temp -> right);
        }
        if(temp -> left){
            s.push(temp -> left);
        }
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "Preorder traversal: " << endl;
    preorderTrav(root);

    return 0;
}