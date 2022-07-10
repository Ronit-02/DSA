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
void inorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

// Iterative method using Stack
void inorderTrav(node* root){

    // empty stack
    stack<node *> s;
    node* curr = root;

    while(curr != NULL || !s.empty()){

        // push items of root->left till 'NULL'
        while(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }

        // pop item
        curr = s.top();
        s.pop();
        
        cout << curr -> data << " ";

        // pop_item -> right
        curr = curr -> right;
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    inorderTrav(root);

    return 0;
}