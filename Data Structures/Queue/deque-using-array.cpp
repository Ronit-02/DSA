#include<iostream>

using namespace std;

class Deque{
public:
    int *arr;
    int front;
    int rear;
    int size;

    // constructor
    Deque(){
        size = 100001;
        arr = new int[size];
        front = rear = -1;
    }

    // destructor
    ~Deque(){

    }

    void pushFront(int data){
        // full case
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1)) ){
            cout << "Queue is full";
            return;
        }
        // inserting 1 element
        else if(front == -1){
            front = rear = 0;
        }
        // to maintain cyclic nature
        else if(front == 0){
            front = size-1;
        }
        // normal flow
        else{
            front--;
        }

        arr[front] = data;
    }

    void pushRear(int data){
        // full case
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1)) ){
            cout << "Queue is full";
            return;
        }
        // inserting 1 element
        else if(rear == -1){
            front = rear = 0;
        }
        // to maintain cyclic nature
        else if(rear == size-1){
            rear = 0;
        }
        // normal flow
        else{
            rear++;
        }

        arr[rear] = data;
    }

    void popFront(){
        // empty case
        if(front == -1){
            cout << "Queue is empty";
            return;
        }
        // 1 element remaining
        else if(front == rear){
            front = rear = -1;
        }
        // to maintain cyclic nature
        else if(front == size-1){
            front = 0;
        }
        // normal flow
        else{
            front++;
        }
    }

    void popRear(){
        // empty case
        if(rear == -1){
            cout << "Queue is empty";
            return;
        }
        // 1 element remaining
        else if(front == rear){
            front = rear = -1;
        }
        // to maintain cyclic nature
        else if(rear == 0){
            rear = size-1;
        }
        // normal flow
        else{
            rear--;
        }
    }
};

int main(){


    return 0;
}