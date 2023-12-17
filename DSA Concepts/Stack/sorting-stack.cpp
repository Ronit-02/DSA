#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> &s, int x){

    // base cases
    if(s.empty()){    // all values are greater -> insert at bottom
        s.push(x);
        return;
    }
    if(s.top() < x){   // inserting x above smaller value
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    sortedInsert(s, x);

    s.push(num);
}

void sort(stack<int> &s){

    // base case
    if(s.empty()){
        return;
    }

    int x = s.top();
    s.pop();
    
    sort(s);
    
    sortedInsert(s, x);
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
    s.push(4);
    s.push(3);
    s.push(2);

    print(s);
    cout << endl;

    sort(s);
    print(s);    

    return 0;
}