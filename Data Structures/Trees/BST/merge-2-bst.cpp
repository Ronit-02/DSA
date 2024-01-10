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

// BST to inorder
void inorder(node *root, vector<int> &in){
    
    if(root==NULL)
        return;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}
// Merging
vector<int> merge(vector<int> in1, vector<int> in2){
    
    vector<int> in(in1.size() + in2.size());
    
    int i=0, j=0, k=0;
    
    while(i < in1.size() && j < in2.size()){
        
        if(in1[i] < in2[j])
            in[k++] = in1[i++];
        else
            in[k++] = in2[j++];
    }
    
    while(i < in1.size())
        in[k++] = in1[i++];
        
    while(j < in2.size())
        in[k++] = in2[j++];
        
    return in;
}
vector<int> merge(node *root1, node *root2)
{
    // 1: calculate inorder traversal
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);
    
    // 2: calculate merged inorder
    vector<int> in = merge(in1, in2);
    
    return in;
}

int main(){

    node *root1 = NULL;
    takeInput(root1);
    // 10 5 21 3 7 11 25 -1

    node *root2 = NULL;
    takeInput(root2);
    // 5 3 6 2 4 -1

    merge(root1, root2);

    return 0;
}