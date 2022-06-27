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

    void print();
    void insertAtHead();
    void insertAtTail();
};

void insertAtHead(Node* &head, int data){


}

int main(){

    // Created first node
    Node *node1 = new Node(10);
    cout << node1->data << endl; 
    cout << node1->next;

    // Head pointing to first node
    Node *head = node1;

    // Inserting 
    


    return 0;
}