#include<iostream>

using namespace std;

class Queue{
public:
    // data items
    int *arr;
    int front;
    int rear;
    int size;

    // constructor
    Queue(int size){
        this->size = size;
        arr = new int[size];  
        front = 0;
        rear = 0;
    }

    // destructor
    ~Queue(){

    }

    void push(int x){
        // full case
        if(rear == size){
            cout << "Queue is full";
        }
        else{
            arr[rear] = x;
            rear++;
        }
    }

    void pop(){
        // empty case
        if(front == rear){
            cout << "Queue is empty";
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int front(){
        // empty case
        if(front == rear)
            return -1;
        else
            return arr[front];
    }

    void print(){

        for(int i = front; i < rear; i++){
            cout << arr[i] << " ";
        }
        cout<< endl;
    }
};

int main(){

    Queue q(10);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    return 0;
}