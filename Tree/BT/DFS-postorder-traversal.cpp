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
vector<int> postorderTrav(node* root){

    vector<int> post;

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

    // contents of 2nd stack 
    while(!s2.empty()){
        node *temp = s2.top();
        post.push_back(temp -> data);
        s2.pop();
    }       
    return post;
}

int main(){

    node* root = NULL;
    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Postorder traversal: " << endl;
    vector<int> post = postorderTrav(root);
    for(auto i : post)
        cout << i << " ";

    return 0;
}