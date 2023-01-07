#include <iostream>
#include <string.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    cin.get();      //consuming extra \n in n

    char string[1000];
    char largest_string[1000];

    int largest_len = 0;
    
    while(n--){

        cin.getline(string, 1000);

        int len = strlen(string);
        if(len > largest_len){
            largest_len = len;
            strcpy(largest_string, string);
        }
    }
    cout<< "Largest String: " <<largest_string;

    return 0;
}