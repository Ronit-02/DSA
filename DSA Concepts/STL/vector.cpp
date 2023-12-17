#include <iostream>
#include <vector>
using namespace std;

int main() {

    // 1d vectors
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


    // 2d vectors
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> vect2(3, vector<int> (3, 0));  // value 0


    // vectors of pairs
    vector< pair<int, int> > p = {{1,2},{3,4}};

    p.push_back(make_pair(5,6));
    p.push_back({7,8});
    
    cout << "pairs: ";
    for(auto it: p)
        cout << it.first << "-" << it.second << " ";
    cout << endl;

    // deleting vector at position 0
    p.erase(p.begin() + 0);


    // array of vectors: type of 2d vector
    vector<int> ar[10];

    ar[0] = {1,2,3};
    ar[1] = {4,5};

    cout << "vectors: ";
    for(auto vec: ar){
        for(auto x: vec)
            cout << x << " ";
        cout << endl;
    }


    // iterators
    vector<int> v = {1,2,3,4};

    vector<int> ::iterator it;
    for(it = v.begin(); it < v.end(); it++){
        cout << *(it);
    }
    cout << endl;
    // it++ -> next iterator
    // it+1 -> next location
    // vector are cts (it++ and it+1 both works)
    // maps are discts (it++ will work but it+1 won't)
    
    vector<pair<int,int>> v_p = {{1,2},{2,4}};
    vector <pair<int,int>> ::iterator it_p;
    for(it_p = v_p.begin(); it_p < v_p.end(); it_p++){
        cout << (*it_p).first << "-" << it_p->second << " ";
    }
    cout << endl;
    // (*it).first <=> it->first




    return 0;
}