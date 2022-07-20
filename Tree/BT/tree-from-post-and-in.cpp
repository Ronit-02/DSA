#include<iostream>
#include<queue>
#include<map>

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

node *solve(int in[], int post[], int inStart, int inEnd, int postEnd, int n){
    
    // base case
    if(inStart > inEnd || postEnd < 0)
        return NULL;
        
    node *root = new node(post[postEnd]);
    
    // calculating root index in inorder
    int inRoot = 0;
    for(int i = inStart; i <= inEnd; i++){
        if(root -> data == in[i])
            inRoot = i;
    }
    
    int numsRight = inEnd - inRoot;
    
    // left subtree
    root -> left = solve(in, post, inStart, inRoot-1, postEnd-numsRight-1, n);
    // right subtree
    root -> right = solve(in, post, inRoot+1, inEnd, postEnd-1, n);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
node *buildTree(int in[], int post[], int n) {
    
    return solve(in, post, 0, n-1, n-1, n);
}

// Recursive Method
void preorderTrav(node *root){

    if(root == NULL)
        return;

    preorderTrav(root -> left);
    preorderTrav(root -> right);
    cout << root -> data << " ";
}

int main(){

    int in[] = {4,2,5,1,6,3};
    int post[] = {4,5,2,6,3,1};
    int n = sizeof(in)/sizeof(int);

    node* root = buildTree(in, post, n);

    cout << "Preorder Traversal: " << endl;
    preorderTrav(root);

    return 0;
}