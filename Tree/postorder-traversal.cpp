#include<iostream>
#include<stack>

using namespace std;

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

    // base case
    if(data == -1)
        return NULL;

    root = new node(data);

    // left root node
    root -> left = buildTree(root -> left);

    // right root node
    root -> right = buildTree(root -> right);

    return root;
}

// Recursive method
void postorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}

// Iterative method using 2 Stacks
void postorderTrav(node* root){

    stack<node *> s1;
    stack<node *> s2;

    s1.push(root);

    while(!s1.empty()){

        // pop root from first and push it to second
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        // push root->left and root->right to first
        if(temp -> left){
            s1.push(temp -> left);
        }
        if(temp -> right){
            s1.push(temp -> right);
        }
    }

    // print contents of second stack 
    while(!s2.empty()){
        node *temp = s2.top();
        cout << temp -> data << " ";
        s2.pop();
    }       
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    postorderTrav(root);

    return 0;
}