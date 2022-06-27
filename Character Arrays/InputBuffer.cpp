#include <iostream>
#include <vector>

using namespace std;

int main(){

    char sentence[100];

    char temp = cin.get();      //reads from the input buffer (reading char by char)

    vector <char> arr;

    int len = 1;
    while(temp != '\n'){        //temp != #  <--  will wait for the input(#) 
        len++;
        cout<< temp;

        arr.push_back(temp);

        //reading next char
        temp = cin.get();
    }

    cout<< "Length: " <<len <<endl;
    cout<< "Char arr: ";
    for(char x:arr){
        cout<<x;
    }

    return 0;
}