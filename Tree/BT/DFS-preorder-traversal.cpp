#include<iostream>
#include<queue>
#include<stack>
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

// Recursive Method
void preorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

// Iterative method using 1 Stack
// Method: pop, add left and right
vector<int> preorderTrav(node* root){

    vector<int> pre;

    stack<node*> s;
    s.push(root);

    while(!s.empty()){

        // root value
        node *curr = s.top();
        s.pop();
        
        // add
        pre.push_back(curr -> data);

        // push right and left
        if(curr -> right){
            s.push(curr -> right);
        }
        if(curr -> left){
            s.push(curr -> left);
        }
    }
    return pre;
}

int main(){

    node* root = NULL;
    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Preorder traversal: " << endl;
    vector<int> pre = preorderTrav(root);
    for(auto i : pre)
        cout << i << " ";

    return 0;
}