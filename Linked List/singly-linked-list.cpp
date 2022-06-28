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
        cout << "Memory is free for node with data = " << value;
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

void insertAtHead(Node* &head, Node* &tail, int d){

    if(head == NULL){         // empty list case
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(d);   // creating new node
        temp->next = head;      // new node points to head
        head = temp;    // head goes at start again
    }
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
    temp->next = nodeToInsert;

    // Inserting at ending
    if(nodeToInsert->next == NULL){
        tail = nodeToInsert;
    }   
    
}

void insertAtTail(Node* &head, Node* &tail, int d){

    if(tail == NULL){       // empty list case
        Node *temp =  new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node *temp = new Node(d);   // creating new node
        tail->next = temp;     // tail points at temp
        tail = temp;     // tail goes forward
    }
}

void deleteNode(Node* &head, Node* &tail, int position){

    Node *temp = head;

    // Deleting from starting
    if(position == 1){
        head = head->next;
        temp = NULL;
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
    nodeToDelete = NULL;     // before deleting make sure its pointing to null
    delete nodeToDelete;

    // Deleting from ending
    if(temp->next == NULL){
        tail = temp;
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    print(head);
    insertAtHead(head,tail , 10);
    print(head);
    
    insertAtTail(head, tail, 40);
    print(head);

    insertAtPosition(head, tail, 3, 25);
    print(head);

    deleteNode(head, tail, 4);
    print(head);
    deleteNode(head, tail, 1);
    print(head);

    

    return 0;
}