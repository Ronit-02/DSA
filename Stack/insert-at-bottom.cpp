#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    // removing
    s.pop();
    // recursive call
    insertAtBottom(s, x);
    // adding
    s.push(num);
}

void print(stack<int> s){

    stack<int> temp = s;

    while(!temp.empty()){
        cout << temp.top() << endl;
        temp.pop();
    }
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    print(s);
    cout << endl;

    insertAtBottom(s, 0);
    print(s);

    return 0;
}