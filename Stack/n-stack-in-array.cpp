#include<iostream>
#include<stack>

using namespace std;

class NStack{

public:
    int n, m, freespot;

    int *arr;    // to store elements
    int *top;    // indicates top element
    int *next;   // indicates next element present, next freespot available

    NStack(int n, int m){

        this->n = n;
        this->m = m;

        arr = new int[n];
        top = new int[m];
        next = new int[n];

        // top initialize
        for(int i=0; i<m; i++)
            top[i] = -1;

        // next initialize
        for(int i=0; i<n; i++)
            next[i] = i+1;
        next[n-1] = -1;

        // freespot initialize
        freespot = 0;
    }

    // x - number, mth stack
    void push(int x, int m){

        if(freespot == -1){
            cout << "Stack overflow";
            return;
        }

        // calculating index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;
    }

    void pop(int m){

        if(top[m-1] == -1){
            cout << "Stack underflow";
            return;
        }

        int index = top[m-1];

        arr[index] = 0;
     
        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;
    }

    void print(){

        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){

    NStack s(6, 3);

    s.push(1, 1);   // push in 1st stack
    s.push(2, 1);   // push in 2nd stack

    s.push(3, 2);
    s.push(2, 2);

    s.pop(2);      // pop from 2nd stack

    s.print();


    return 0;
}