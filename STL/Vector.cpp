#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {1,2,3,4,5};
    vector<int> arr1(5, 1);  // initialize with 1

    arr.push_back(6);

    // capicity indicates how much memory allocated (doubles on full)
    cout << "size: " << arr.size() << endl;
    cout << "capacity: " << arr.capacity() << endl;

    arr.pop_back();
    
    cout << "elements: ";
    for(auto i: arr){
        cout<< i << " ";
    }
    
    cout << endl;
    cout << "element at 2nd index = " << arr.at(2) << endl;

    // clearing: size = 0 and capacity = remains same
    arr.clear();
    cout << "size: " << arr.size() << endl;
    cout << "capacity: " << arr.capacity() << endl;


    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> vect2(3, vector<int> (3, 0));  // value 0


    vector< pair<int, int> > p = {{1,2},{3,4}};

    p.push_back(make_pair(5,6));
    p.push_back({7,8});
    
    for(auto it: p)
        cout << it.first << ", " << it.second;

    // deleting vector at position 0
    p.erase(p.begin() + 0);


    return 0;
}