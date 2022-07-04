void print(stack<int> s){

    stack<int> temp = s;

    while(!temp.empty()){
        cout << temp.top() << endl;
        temp.pop();
    }
}