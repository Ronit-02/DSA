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

// Using just 1 stack (node, num)
void allTraversals(node *root){

    vector<int> pre, in, post;

    stack< pair<node*, int>> s;   // node and num
    s.push({root, 1});

    while(!s.empty()){

        pair<node*,int> temp = s.top();
        s.pop();
        
        // preorder, 1 -> 2, push left
        if(temp.second == 1){
            pre.push_back(temp.first -> data);
            temp.second++;
            s.push(temp);

            if(temp.first -> left){
                s.push({temp.first->left, 1});
            }
        }
        // inorder, 2 -> 3, push right
        else if(temp.second == 2){
            in.push_back(temp.first -> data);
            temp.second++;
            s.push(temp);

            if(temp.first -> right){
                s.push({temp.first->right, 1});
            }
        }
        // dont push back again
        else{
            post.push_back(temp.first -> data);
        }
    }

    // printing
    cout << "Preorder Traversal:" << endl;
    for(auto i: pre){
        cout << i <<" ";
    }
    cout << endl;
    cout << "Inorder Traversal:" << endl;
    for(auto i: in){
        cout << i <<" ";
    }
    cout << endl;
    cout << "Postorder Traversal:" << endl;
    for(auto i: post){
        cout << i <<" ";
    }
    cout << endl;

}

int main(){

    node* root = NULL;
    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1  

    allTraversals(root);

    return 0;
}