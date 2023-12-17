#include<iostream>
#include<array>

using namespace std;

int main(){

    array<int, 4> arr = {1,2,3,4};
    array<int, 0> arr2;

    int n = arr.size();

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Element at 2nd index = " << arr.at(0) << endl;

    // 0 -> not empty
    // 1 -> empty
    cout << "Empty or not: " << arr2.empty() << endl;

    cout << "First element = " << arr.front() << endl;
    cout << "Last element = " << arr.back() << endl;

    return 0;
}