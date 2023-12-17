#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // one liner functions which are inline
    // return type is not mandatory (compiler can detect)

    // [ capture clause ] (parameters) -> return-type  
    // {   
    //    definition of method   
    // }

    auto sum = [](int x, int y) -> int {return x+y;};
    cout << "sum: " << sum(5,3) << endl;

    // all_of, any_of, none_of function
    // used to apply a function on every array element

    vector<int> arr = {2,1,4};
    cout << all_of(arr.begin(), arr.end(), [](int x) -> bool
    {
        return x % 2 == 0;
    });
    cout << any_of(arr.begin(), arr.end(), [](int x) -> bool
    {
        return x > 0;
    });
    cout << endl ;

    // custom sort
    // lambda fn in custom sorting looks clean

    sort(arr.begin(), arr.end(), [](int x, int y) -> bool
    {
        return x < y;
    });
    for(auto x: arr)    
        cout << x << " ";


    return 0;
}