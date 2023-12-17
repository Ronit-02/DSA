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

// using queue doing it in O(N)
vector<int> diagonalTraversal(node *root){
    
    // pushing left node in queue
    // accessing front of queue
    // pushing right node in answer

    vector<int> ans;
    queue<node *> q;
    q.push(root);

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        while(temp != NULL){
            if(temp->left){ 
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            
            temp = temp->right;
        }
    }
    return ans;
}

int main(){

    node* root = NULL;

    buildTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Diagonal Traversal: " << endl;
    vector<int> ans;
    
    ans = diagonalTraversal(root);
    for(auto i:ans){
        cout << i << " ";
    }

    return 0;
}