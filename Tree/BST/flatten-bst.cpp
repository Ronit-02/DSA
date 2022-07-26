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

void inorder(node *root, vector<int> &in){

    if(root == NULL)
        return;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

// Intuition: calculating inorder(ascending) and creating linked list with it
node *flatten(node *root){

    vector<int> in;
    inorder(root, in);

    node *newRoot = new node(in[0]);
    node *curr = newRoot;

    for(int i = 1; i < in.size(); i++){

        node *temp = new node(in[i]);
        curr -> right = temp;
        curr = temp;
    }

    return newRoot;
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

int main(){

    node *root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    // 10 5 21 3 7 11 25 -1

    node *newRoot = flatten(root);

    cout << "Printing: " << endl;
    levelOrderTraversal(newRoot);

    return 0;
}