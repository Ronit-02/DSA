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

// Recursive Approach
// TC: O(logn)
// SC: O(n)
bool find(node* root, int x){

    // base case
    if(root == NULL){
        return false;
    }
    
    if(root->data == x){
        return true;
    }
    else if(root->data > x){
        return find(root->left, x);
    }
    else{
        return find(root->right, x);
    }
}

// Iterative Approach
// TC: O(logn)
// SC: O(1)
bool searchInBST(node *root, int x){

    node *curr = root;

    while(curr != NULL){

        if(curr->data == x)
            return true;
        
        if(curr->data > x)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return false;
}

int main(){

    node *root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    // 10 5 21 3 7 11 25 -1

    cout << searchInBST(root, 21);

    return 0;
}