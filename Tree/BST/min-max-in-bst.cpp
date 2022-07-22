#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insertIntoBST(node* root, int data){

    // initial case
    if(root == NULL){
        root = new node(data);
        return root;
    }
    
    if(data <= root -> data)
        root -> left = insertIntoBST(root -> left, data);
    else
        root -> right = insertIntoBST(root -> right, data);

    return root;
}

void takeInput(node* &root){

    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Iterative 
int minInBST(node *root){

    while(root->left != NULL)
        root = root->left;

    return root->data;
}

// Iterative 
int maxInBST(node *root){

    while(root->right != NULL)
        root = root->right;

    return root->data;
}

int main(){

    node *root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    // 10 5 21 3 7 11 25 -1

    cout << "Min value: " << minInBST(root) << endl;
    cout << "Max value: " << maxInBST(root) << endl;

    return 0;
}