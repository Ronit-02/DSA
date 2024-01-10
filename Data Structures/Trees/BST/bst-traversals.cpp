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

// Iterative Approach (using stack)
void inorder(node* root){

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
        cout << curr -> data << " ";

        // go to right of pop_item
        curr = curr -> right;
    }
}

// Iterative Approach (using queue)
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

    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal: " << endl;
    inorder(root);

    return 0;
}