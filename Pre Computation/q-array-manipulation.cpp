#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: https://www.hackerrank.com/challenges/crush/problem
// Constraints: n = 10^7

// Intuition: using prefix sum
// Time Complexity: O(n)
const int N = 1e7+10;
long long int pf[N];
long arrayManipulation(int n, vector<vector<int>> queries) {

    for(int i=0; i<queries.size(); i++){  // O(M)
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        pf[a] = pf[a] + k;
        pf[b+1] = pf[b+1] - k;
    }

    for(int i=1; i<=n; i++){   // O(N)
        pf[i] += pf[i-1];
    }

    long long mx = -1; 
    for(int i=1; i<=n; i++){  // O(N)
        mx = max(mx, pf[i]);
    }

    return mx;
}

int main(){
    
    int n = 10;
    vector<vector<int>> queries = {{1,5,3},{4,8,7},{6,9,1}};

    cout << arrayManipulation(n, queries);
    
    return 0;
}