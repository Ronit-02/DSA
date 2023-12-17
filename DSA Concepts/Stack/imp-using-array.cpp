#include<iostream>

using namespace std;

class Stack{

public:
    // properties
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int(size);
        top = -1;
    }

    void push(int x){
        if(top == size-1){
            cout << "Stack overflow";
            return;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    void pop(){
        if(top < 0){
            cout << "Stack underflow";
        }
        else{
            top--;
        }
    }

    void peek(){
        if(top < 0){
            cout << "Stack is empty";
        }
        else{
            cout << arr[top];
        }
    }
};

int main(){

    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.peek();

    return 0;
}