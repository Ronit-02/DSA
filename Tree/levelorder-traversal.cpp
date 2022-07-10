#include<iostream>
#include<queue>

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

node* buildTree(node* root){

    int data;
    // cout << "Enter the data: " << endl;
    cin >> data;

    // null case
    if(data == -1)
        return NULL;

    // root node
    root = new node(data);

    // left node
    // cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    // right node
    // cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

// Iterative approach
void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            // if queue still have child nodes
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
             // if left node is present
            if(temp -> left){  
                q.push(temp -> left);
            }
            // if right node is present
            if(temp -> right){   
                q.push(temp -> right);
            }
        }
    }
}

int main(){

    node* root = NULL;

    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "Printing level order traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}