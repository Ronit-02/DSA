#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<string>& products){

    for(int i=0; i<products.size(); i++)
        cout << products[i] << " "; 
        cout << endl;
}

static bool sortByLength(string s1, string s2){

    return s1.length() < s2.length();
}

int main(){

    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};

    print(products);

    sort(products.begin(), products.end(), sortByLength);

    print(products);

    return 0;
}