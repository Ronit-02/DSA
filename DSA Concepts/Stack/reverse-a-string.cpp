#include<iostream>
#include<stack>

using namespace std;

int main(){

    string str = "hello";
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    string ans = "";
    for(int i=0; i<str.length(); i++){
        ans += s.top();
        s.pop();
    }

    cout << ans ;

    return 0;
}