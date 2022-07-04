#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &St, int x){
        
    // base case
    if(St.empty()){
        St.push(x);
        return;
    }
    
    int num = St.top();
    St.pop();
    
    insertAtBottom(St, x);
    
    St.push(num);
}
void reverse(stack<int> &St){

    // base case
    if(St.empty())
        return;
    
    // save and remove
    int x = St.top();
    St.pop();
    
    // recursive call 
    reverse(St);
    
    // add it at last
    insertAtBottom(St, x);
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

    reverse(s);
    print(s);    

    return 0;
}