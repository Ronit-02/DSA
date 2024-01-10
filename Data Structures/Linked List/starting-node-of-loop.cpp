#include<iostream>

using namespace std;

struct Node{

    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }

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

    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " "; 
        temp = temp->next;    
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int d){

    if(tail == NULL){     
        Node *temp =  new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node *temp = new Node(d);   
        tail->next = temp;     
        tail = temp;     
    }
}

Node* getStartingNode(Node* head){
    
    Node* slow = head;
    Node* fast = head;

    // bringing slow and fast at same node
    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast);
    
    slow = head;  // updating slow to start

    // when they again reach at same node, its always starting of loop
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;   // fast updates 1x now
    }

    return slow;    
}
int main(){

    Node *head = NULL;
    Node *tail = NULL;
    
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    tail -> next = head -> next;   // making a loop 

    Node* x = getStartingNode(head);
    cout << x -> data;

    return 0;
}