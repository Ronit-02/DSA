#include <iostream>
#include <string>

using namespace std;

bool isNumeric(string str, int n){
    
    for(int i=0; i<n; i++){
        
        if(str[i]>='0' && str[i] <='9')
            return true;
    }
    return false;
}

bool isUpper(string str, int n){
    
    for(int i=0; i<n; i++){
        
        if(isupper(str[i]))
            return true;
    }
    return false;
}

bool isLower(string str, int n){
    
    for(int i=0; i<n; i++){
        
        if(islower(str[i]))
            return true;
    }
    return false;
}

bool isSpecial(string str, int n){
    
    for(int i=0; i<n; i++){
        
        if ((str[i]>=48 && str[i]<=57) || (str[i]>=65 && str[i]<=90)|| (str[i]>=97 && str[i]<=122))
            continue;
        else
            return true;
    }
    return false;
}

int main(){
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    if(isNumeric(str, n)!= true)
        str += '1';
        
    if(isLower(str, n)!= true)
        str += 'a';
        
    if(isUpper(str, n)!= true)
        str += 'A';
        
    if(isSpecial(str, n)!= true)
        str += '@';
        
    while( str.length() < 7){
        str += '1';
    }
    
    cout<< "Ans is = " << str;
    return 0;
}