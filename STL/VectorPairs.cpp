#include <vector>
#include <iostream>
using namespace std;

int main() {

    // declaring vector pairs
    vector< pair <int, int> > arr = {
        {1,2},{3,4}
    };

    // pushing
    arr.push_back(make_pair(5,6));

    // printing
    for(int i=0; i<arr.size(); i++){
        cout <<arr[i].first <<", " <<arr[i].second;
        cout<<endl;
    }

    // deleting vector at position i
    arr.erase(arr.begin() + 0);

    // printing
    cout <<"After deleting: \n";
    for(int i=0; i<arr.size(); i++){
        cout <<arr[i].first <<", " <<arr[i].second;
        cout<<endl;
    }

        return 0;
}