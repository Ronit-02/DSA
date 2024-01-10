#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool redundant(string &str){

    stack<char> s;
    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        
        // found a opening bracket or operator
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            s.push(ch);
        }
        
        // found a closing bracket
        else if(ch == ')'){

            bool redundant = true;

            while(s.top() != '('){

                char top = s.top();
                
                // if operator is found -> not redundant
                if(top == '+' || top == '-' || top == '/' || top == '*')
                    redundant = false;
                s.pop();
            }
            s.pop();   // removing opening bracket
            
            if(redundant == true)
                return true;            
        }

    }
    return false;
}

int main(){

    string str = "(a+b)";

    if(redundant(str) == true)
        cout << "Yes it is";
    else
        cout << "No";   

    return 0;
}