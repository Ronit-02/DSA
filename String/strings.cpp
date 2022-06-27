#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // checking if a string is palindrome or no 

    string str;
    getline(cin, str);
    int flag = 0;

    for(int i=0; i < str.length() / 2; i++){
        if(str[i] != str[ str.length() - i - 1 ])
            flag = 1;
    }

    if(flag == 1)
        cout << "not palindrome";
    else 
        cout << "is palindrome";

    return 0;
}