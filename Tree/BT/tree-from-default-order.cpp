#include<iostream>
#include<queue>

using namespace std;

// Method:
// building tree by inserting all nodes manually, for every
// node inserting left and right child

struct node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root){

    int data;
    cin >> data;

    // null case
    if(data == -1)
        return NULL;

    root = new node(data);
    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);

    return root;
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

int main(){

    node* root = NULL;

    // use this order: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root = buildTree(root);

    cout << "Printing Preorder Traversal: " << endl;
    preorderTraversal(root);

    return 0;
}