#include<iostream>

using namespace std;

struct Node{

    int data;
    Node *next;

    // constructor
    Node(int data){
        this -> data = data;
        next = NULL;
    }
    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data = " << value << endl;
    }
};

void print(Node* &tail){

    Node *temp = tail;    // temp pointing at head

    do{
        cout << temp->data << " ";
        temp = temp -> next;

    }while(temp != tail);

    cout << endl;
}

void insertNode(Node* &tail, int element, int d){

    // empty list case
    if(tail == NULL){         
        Node* newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
    }
    // atleast 1 element is present
    // assuming element is already present
    else{
        Node* curr = tail;

        while(curr->data != element)
            curr = curr->next;

        // curr is representing element node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int val){

    // empty list case
    if(tail == NULL)
        cout << "List is empty !!" << endl;

    else{
        Node* curr = tail;
        Node* prev = curr;

        while(curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        
        if(tail == curr)     // case when tail is pointing to curr
            tail = prev;
        if(curr == prev)   // when 1 node is present
            tail = NULL;
        
        curr->next = NULL;    // make sure its pointing to NULL before deleting
        delete curr;
    }
}

int main(){

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    
    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 4);
    print(tail);

    

    return 0;
}