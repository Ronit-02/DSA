#include<iostream>

using namespace std;

struct Node{

    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data){
        this -> data = data;
        prev = NULL;
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

void print(Node* &head){

    Node *temp = head;    // temp pointing at head

    while(temp != NULL){
        cout << temp->data << " ";   // printing data
        temp = temp->next;        // updating
    }
    cout << endl;
}

void insertAtHead(Node* &head, int d){

    Node *temp = new Node(d); 
    temp->next = head;   
    head->prev = temp;   
    head = temp;   
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    // Inserting at starting
    if(position == 1){
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        return;
    }

    // Inserting at any other position
    Node *temp = head; 

    // temp at (position - 1)
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    Node *nodeToInsert = new Node(d);
   
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

    // Inserting at ending
    if(nodeToInsert->next == NULL){
        tail = nodeToInsert;
    }   
    
}

void insertAtTail(Node* &tail, int d){

    Node *temp = new Node(d);
    tail->next = temp;    
    temp->prev = tail;
    tail = temp;   
    
}

void deleteNode(Node* &head, Node* &tail, int position){

    Node *temp = head;

    // Deleting from starting
    if(position == 1){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // temp at (position - 1)
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    nodeToDelete = NULL;     // before deleting make sure its pointing to null
    delete nodeToDelete;

    // Deleting from ending
    if(temp->next == NULL){
        tail = temp;
    }
}

int main(){

    // Created first node
    Node *node1 = new Node(30);

    // Head and Tail pointing to first node
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 20);
    print(head);
    insertAtHead(head, 10);
    print(head);
    
    insertAtTail(tail, 40);
    print(head);

    insertAtPosition(head, tail, 3, 25);
    print(head);

    deleteNode(head, tail, 4);
    print(head);
    deleteNode(head, tail, 1);
    print(head);

    

    return 0;
}