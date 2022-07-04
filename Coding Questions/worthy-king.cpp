#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int recur(unordered_map<int, int> &freq, int n, int day, int x, int troops){

    if(n == 0)
        return day;
    
    if(freq[troops] > 0){   // if you can find those troops -> defeat them    
        
        freq[troops]--;
        n--;
        if(n == 0)
            return day;

        x = x+1;
        return recur(freq, n, day+1, x, x);
    }
    else{
        
        troops = troops + x;
        day = day + 1;
        return recur(freq, n, day, x, troops);
    }
}

int solve(vector<int> &A) {

    int n = A.size();

    unordered_map<int, int> freq;

    for(int i=0; i<n; i++){

        if(freq.find(A[i]) != freq.end())
            freq[A[i]]++;
        else
            freq[A[i]] = 1;
    }
    
    int day = 1, x = 1, troops = 1;
    day = recur(freq, n, day, x, troops);
    
    return day;
}

int main(){

    vector<int> a = {9, 9};
    int ans = solve(a);

    cout << ans;

    return 0;
}