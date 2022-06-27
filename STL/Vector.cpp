#include<vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> arr = {1,2,3,4,5};

    //Size of Vector
    cout <<"Size of the vector: " <<arr.size() <<endl;

    //Pushing
    arr.push_back(6);

    //Capacity of Vector (which changes on pushing)
    cout <<"Capacity: " <<arr.capacity() <<endl;

    //Printing the vector
    for(int i=0; i<arr.size(); i++){
        cout<< arr[i];
    }

    cout<<endl;

    //Popping
    arr.pop_back();
    for(int i=0; i<arr.size(); i++){
        cout<< arr[i];
    }


        return 0;
}