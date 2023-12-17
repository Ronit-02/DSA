#include<iostream>
#include<queue>

using namespace std;

int main(){

    queue<int> q;

    q.push(3);
    q.push(4);
    q.push(5);

    cout << "\nSize = " << q.size();
    cout << "\nFront = " << q.front();

    // removed from the front (FIFO)
    q.pop();
    cout << "\nFront = " << q.front();

    return 0;
}