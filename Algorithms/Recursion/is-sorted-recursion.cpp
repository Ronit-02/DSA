#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector <int> arr, int i){

    // Base Case
    if(i == arr.size() - 1)
        return true;

    // Recursive Call
    if(arr[i] <= arr[i+1]){
        bool ans = isSorted(arr, i+1);
        return ans;
    }
    else
        return false;
    
}

int main(){

    vector<int> arr{1,1,2,4,9,6};
    
    if(isSorted(arr, 0))
        cout << "Yes";
    else
        cout << "No";
    // cout << output << endl;

    return 0;
}