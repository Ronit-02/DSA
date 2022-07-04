#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

class Stack{

public:
    // properties
    Node* top = NULL;

    // behaviour
    void push(int data){
        if(top == NULL){
            Node* newNode = new Node(data);
            newNode -> next = top;
            top = newNode;
        }
        else{
            Node* newNode = new Node(data);
            newNode -> next = top;
            top = newNode;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "Stack underflow";
        }
        else{
            top = top -> next;
        }
    }

    void peek(){
        if(top == NULL){
            cout << "Stack underflow";
        }
        else{
            cout << top -> data;
        }
    }
};


int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.peek();

    return 0;
}