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

node *solve(int in[], int pre[], int preStart, int inStart, int inEnd, int n){
    // base cases
    if(inStart > inEnd || preStart > n-1){
        return NULL;
    }
    
    node *root = new node(pre[preStart]);
    
    // calculating root position
    int inRoot = 0;
    for(int i = inStart; i <= inEnd; i++){
        if(root -> data == in[i])
            inRoot = i;
    }
    
    int numsLeft = inRoot - inStart;
    
    // left subtree
    root -> left = solve(in, pre, preStart+1, inStart, inRoot-1, n);
    
    // right subtree
    root -> right = solve(in, pre, preStart+numsLeft+1, inRoot+1, inEnd, n);
                        
    return root;
}

node* buildTree(int in[],int pre[], int n){
    node *root = NULL;
    root = solve(in, pre, 0, 0, n-1, n);
    
    return root;
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

    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int n = sizeof(in)/sizeof(int);

    node* root = buildTree(in, pre, n);

    cout << "Preorder Traversal: " << endl;
    preorderTrav(root);

    return 0;
}