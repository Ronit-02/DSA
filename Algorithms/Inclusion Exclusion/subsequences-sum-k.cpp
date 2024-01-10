#include<iostream>
#include<vector>

using namespace std;

// TC: O(2^k * l), l = avg length

// Intuition: 
// We have to go through each number and decide whether to pick
// or not pick, then only save the result (add and remove at same place)
void recurSubseq(vector<int> &arr, int k, vector<int> &seq, int ind){

    // base case
    if(ind == arr.size()){
        if(k == 0){
            for(auto it: seq) 
                cout << it << " ";
        }
        return;
    }

    // 1. take
    if(arr[ind] <= k){
        seq.push_back(arr[ind]);
        recurSubseq(arr, k - arr[ind], seq, ind);
        seq.pop_back();   // if we add, then only we remove it
    }

    // 2. not take (remove)
    recurSubseq(arr, k, seq, ind+1);
}

int main(){

    vector<int> arr = {1,2,3};
    int n = 3;

    int k = 5;
    vector<int> seq;
    recurSubseq(arr, k, seq, 0);

    return 0;
}