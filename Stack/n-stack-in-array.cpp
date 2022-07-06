#include<iostream>
#include<stack>

using namespace std;

class NStack{

public:
    int n, m, freespot;

    int *arr;    // to store elements
    int *top;    // indicates what is present currently at where
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

        // update freespot
        freespot = next[index];

        // insert element into array
        arr[index] = x;

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

        top[m-1] = next[index];

        next[index] = freespot;

        arr[index] = 0;

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

    s.push(1, 1);
    s.push(2, 1);

    s.push(3, 2);
    s.push(2, 2);

    s.pop(2);

    s.print();


    return 0;
}