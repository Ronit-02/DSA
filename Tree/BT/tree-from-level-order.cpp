#include<iostream>
#include<queue>

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

        // left node
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left); 
        }

        // right node
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

int main(){

    node* root = NULL;

    // use this order: 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildTree(root);

    cout << "Printing Preorder Traversal: " << endl;
    preorderTraversal(root);

    return 0;
}