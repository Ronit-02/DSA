#include<iostream>
#include<queue>

using namespace std;

void interleaveQueue(queue<int> &q, int n){
    
    queue<int> t;

    // first half elements in another queue
    for(int i=0; i<n/2; i++){

        int val = q.front();
        q.pop();
        t.push(val);
    }

    // interleaving elements at the end of original queue
    while(!t.empty()){

        int val = t.front();
        q.push(val);
        t.pop();

        val = q.front();
        q.push(val);
        q.pop();
    }
}

void print(queue<int> q){

    while(!q.empty()){

        cout << q.front() << " ";
        q.pop();
    }
}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int n = q.size();
    
    interleaveQueue(q, n);

    print(q);

    return 0;
}