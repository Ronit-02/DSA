#include<iostream>
#include<queue>

using namespace std;

int main(){

    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << "\nfront: " << dq.front();
    cout << "\nback: " << dq.back();

    dq.pop_back();
    dq.pop_front();

    cout << "\nfront: " << dq.front();
    cout << "\nback: " << dq.back();

    return 0;
}