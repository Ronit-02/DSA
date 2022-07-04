#include<iostream>
#include<stack>

using namespace std;

int main(){

    // initializing a stack
    stack<int> s;

    // pushing operation
    s.push(2);
    s.push(4);
    s.push(8);

    cout << "Size = " << s.size() << endl;

    // copying stack
    stack<int> a = s;

    // printing elements
    while(!a.empty()){
        cout << a.top();  // extracting top element
        cout << endl;
        a.pop();   // removing top element
    }

    return 0;
}