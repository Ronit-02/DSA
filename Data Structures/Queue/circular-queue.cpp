#include<iostream>

using namespace std;

class CircularQueue{
public:
    // data items
    int *arr;
    int front;
    int rear;
    int size;

    // constructor
    CircularQueue(int size){
        this->size = size;
        arr = new int[size];  
        front = rear = -1;
    }

    // destructor
    ~CircularQueue(){

    }

    void push(int x){
        // full case
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1)) ){
            cout << "Queue is full";
            return;
        }
        // first element to push
        else if(front == -1){
            front = rear = 0;
        }
        // to maintain cyclic nature
        else if(rear == size-1){
            rear = 0;
        }
        // normal push
        else{
            rear++;
        }

        arr[rear] = x;
    }

    void pop(){
        // empty case
        if(front == -1){
            cout << "Queue is empty";
            return;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
    }
};

int main(){

    CircularQueue q(10);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    return 0;
}