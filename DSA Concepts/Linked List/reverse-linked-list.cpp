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

// its returning head of reversed list
Node* reverse(Node* head){
    
    // base case
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* smallhead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallhead;
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;
    
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    print(head);

    head = reverse(head);
    print(head);

    return 0;
}