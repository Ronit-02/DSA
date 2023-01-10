#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    
    set<string> s;

    // insertion: sorts all elements - O(logn)
    s.insert("abv");
    s.insert("def");
    s.insert("erd");

    s.erase("abv");   // O(logn)

    for(auto p: s){
        cout << p << endl;   // O(logn)
    }
    cout << endl;

    // insertion: uses hashing (can't use complex d.s.)
    // no definate ordering
    unordered_set<string> us;   

    us.insert("erd");
    us.insert("def");
    us.insert("abv");  // O(1)

    us.erase("abv");   // O(1)

    for(auto p: us){
        cout << p << endl;   // O(1)
    }
    cout << endl;

    multiset<string> ms;   // duplicates are allowed

    // insertion: sorts all elements - O(logn)
    ms.insert("abv");
    ms.insert("def");
    ms.insert("erd");
    ms.insert("abv");

    ms.erase("erd");   // O(logn)

    for(auto p: ms){
        cout << p << endl;
    }
    
    return 0;
}