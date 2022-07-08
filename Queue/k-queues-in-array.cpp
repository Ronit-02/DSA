#include<iostream>
#include<queue>

using namespace std;

class KQueues{

public:
    // properties
    int n;
    int k;
    int *arr;   // stores values
    int *front;   // stores front index
    int *rear;    // stores rear index
    int *next;   // stores next linked index to that index
    int freespot;   // next freeslot available

    // behaviour
    KQueues(int n, int k){

        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        arr = new int[n];
        next = new int[n];

        // initializing freespot
        freespot = 0;

        // initializing front and rear
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // initializing next
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    // pushing value 'x' in 'qth' queue
    void push(int q, int data){

        // overflow condition
        if(freespot == -1){
            cout << "Queue is full !!" << endl;
            return;
        }

        // calculating index
        int index = freespot;

        // updating freespot
        freespot = next[index];

        
        // pushing first element
        if(front[q-1] == -1){   
            front[q-1] = index;
        }
        // link new element to prev element
        else{
            next[rear[q-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[q-1] = index;

        // pushing element
        arr[index] = data;
    }

    // pop element of 'qth' queue
    void pop(int q){

        // underflow condition
        if(front[q-1] == -1){
            cout << "Queue is empty !!" << endl;
            return;
        }

        // find index
        int index = front[q-1];

        // update front
        front[q-1] = next[index];

        // update next
        next[index] = freespot;

        // update freespot
        freespot = index;
    }

};

int main(){

    KQueues q(10, 3);

    q.push(1,1);
    q.push(2,1);
    q.push(1,2);
    q.push(5,3);

    return 0;
}