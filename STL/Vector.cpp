#include<vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> arr = {1,2,3,4,5};
    vector<int> arr1(5, 1);  // size = 5, with values 1

    //Size of Vector = how many elements are present
    cout <<"Size of the vector: " <<arr.size() <<endl;

    //Pushing
    arr.push_back(6);

    //Capacity = how much is the memory allocated
    // Vector's capacity doubles on full
    cout <<"Capacity: " <<arr.capacity() << endl;

    //Printing the vector
    cout << "Before popping: " << endl;
    for(int i: arr){
        cout<< i << " ";
    }
    cout<<endl;

    //Popping
    arr.pop_back();

    cout << "After popping: " << endl;
    for(auto i: arr){
        cout<< i << " ";
    }
    cout<<endl;

    cout << "Element at 2nd index = " << arr.at(2) << endl;

    // clearing -> size = 0, capacity remains same
    arr.clear();
    cout << "Size: " << arr.size() << endl;
    cout << "Capacity: " << arr.capacity() << endl;

    


    return 0;
}