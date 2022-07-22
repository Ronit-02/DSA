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

// Iterative Approach
void levelOrderTraversal(node *root){

    vector <int> ans;
    queue <node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        for(int i = 0; i < size; i++){

            node *curr = q.front();
            q.pop();

            cout << curr -> data << " ";

            if(curr -> left)
                q.push(curr -> left);
            if(curr -> right)
                q.push(curr -> right);
        }
        cout << endl;
    }
}

// Iterative 
int minInBST(node *root){

    while(root->left != NULL)
        root = root->left;

    return root->data;
}

node* deleteFromBST(node* &root, int x){

    // base case
    if(root == NULL)
        return root;
    
    if(root->data == x){

        // 0 child
        if(root->left == NULL && root->right == NULL)
            return NULL;

        // 1 child
        else if(root->left != NULL && root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        // method 1: min value of right subtree
        // method 2: max value of left subtree
        else{
            int mini = minInBST(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
        }
    }
    else if(root->data > x){
        root->left = deleteFromBST(root->left, x);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}

int main(){

    node *root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    // 10 5 21 3 7 11 25 -1

    cout << "Level order Traversal: " << endl;
    levelOrderTraversal(root);

    deleteFromBST(root, 3);

    cout << "Level order Traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}