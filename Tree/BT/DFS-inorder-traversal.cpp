#include<iostream>
#include<stack>
#include<queue>
#include<vector>

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

// Using level order traversal as i/p
void buildTree(node* &root){

    queue<node*> q;

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

// Iterative method using 1 Stack
vector<int> inorderTrav(node* root){

    vector<int> in;
    
    stack<node *> s;
    node* curr = root;

    while(curr != NULL || !s.empty()){

        // go to left till 'NULL'
        while(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }

        // pop item
        curr = s.top();
        s.pop();
        in.push_back(curr -> data);

        // go to right of pop_item
        curr = curr -> right;
    }

    return in;
}

int main(){

    node* root = NULL;
    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Inorder Traversal: " << endl;
    vector<int> in = inorderTrav(root);
    for(auto i : in)
        cout << i << " ";

    return 0;
}