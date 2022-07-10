#include<iostream>
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

    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "Printing Preorder Traversal: " << endl;
    preorderTraversal(root);

    return 0;
}