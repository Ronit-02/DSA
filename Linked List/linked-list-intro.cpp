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
};

void insertAtHead(Node* &head, int d){

    Node *temp = new Node(d);   // creating new node
    temp->next = head;    // points at starting
    head = temp;    // head gets updated
}

void insertAtTail(Node* &head, int d){

    Node *temp = new Node(d);   // creating new node

}

void print(Node* &head){

    Node *temp = head;    // temp pointing at head

    while(temp->next != NULL){
        cout << temp->data << " ";   // printing data
        temp = temp->next;        // updating
    }
    cout << endl;
}

int main(){

    // Created first node
    Node *node1 = new Node(10);

    // Head pointing to first node
    Node *head = node1;
    // Tail pointing to first node
    Node *tail = node1;

    // Inserting at Head
    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 30);
    print(head);
    
    


    return 0;
}