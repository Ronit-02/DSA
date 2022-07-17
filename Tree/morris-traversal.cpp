#include<iostream>
#include<queue>
#include<vector>

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

// Using level order traversal as i/p
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

        // root -> left data
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left); 
        }

        // root -> right data
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right); 
        }
    }
}

// Threaded Binary Tree Algo. (using temporary links)
vector<int> inorder(node *root){

    vector<int> inorder;
    node *curr = root;

    while(curr != NULL){

        // left subtree not present
        if(curr -> left == NULL){
            inorder.push_back(curr -> data);
            curr = curr -> right;
        }

        // left subtree present
        // link predecessor of curr to curr node (rightmost of left subtree)
        else{
            node *prev = curr -> left;
            while(prev->right && prev->right != curr){
                prev = prev -> right;
            }
            // link is not present, create it
            if(prev -> right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            // link is already present, remove it 
            else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

// Threaded Binary Tree Algo. (using temporary links)
vector<int> preorder(node *root){

    vector<int> preorder;
    node *curr = root;

    while(curr != NULL){

        // left subtree not present
        if(curr -> left == NULL){
            preorder.push_back(curr -> data);
            curr = curr -> right;
        }

        // left subtree present
        // link predecessor of curr to curr node (rightmost of left subtree)
        else{
            node *prev = curr -> left;
            while(prev->right && prev->right != curr){
                prev = prev -> right;
            }
            // link is not present, create it
            if(prev -> right == NULL){
                prev->right = curr;
                preorder.push_back(curr->data);   // just one change .........
                curr = curr->left;
            }
            // link is already present, remove it 
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

int main(){

    node* root = NULL;

    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Inorder Traversal: " << endl;
    vector<int> arr;
    arr = inorder(root);
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;

    cout << "Preorder Traversal: " << endl;
    arr = preorder(root);
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}