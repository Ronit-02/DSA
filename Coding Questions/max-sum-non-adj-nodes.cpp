#include<iostream>
#include<stack>
#include<vector>
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

void preorderTraversal(node* root){

    // base case
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

class Solution {
public:
    int getMaxSum(node *root) 
    {
        queue<node*> q;
        
        int oddSum = 0;
        int evenSum = 0;
        int level = 1;
        
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            // cout << "Size: " << size << endl;
            
            for(int i=0; i<size; i++){
                
                node *temp = q.front();
                q.pop();

                // cout << "Data: " << temp ->data << endl;
                
                if(level % 2 == 0)
                    evenSum += temp -> data;
                else
                    oddSum += temp -> data;
                    
                // cout << "Even: " << evenSum << endl;
                // cout << "Odd: " << oddSum << endl;
                
                if(temp -> left)
                    q.push(temp->left);
                if(temp -> right)
                    q.push(temp->right);
            }

            // cout << "Level increased " << level << endl;
            level ++;
        }
    
        int ans = max(oddSum, evenSum);
        return ans;
    }

};

int main(){

    node* root = NULL;

    buildTree(root);
    // 11 1 2 -1 -1 -1 -1

    cout << "Printing Preorder Traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    Solution s;
    
    int ans = s.getMaxSum(root);
    cout << ans;

    return 0;
}