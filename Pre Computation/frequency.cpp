#include <iostream>
#include <vector>
using namespace std;

// Question: 
// Give the count of element in array

const int N = 1e7+10;
int hsh[N];

// Time Complexity: O(N + N*T)
void freq1(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){  // O(N)
        cin >> a[i];
    }

    int t;
    cin >> t;
    while(--t){   // O(T)
        int n;
        cin >> n;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){  // O(N)
            if(n == a[i]) cnt++;
        }
        cout << cnt << endl;
    }
}

// Time Complexity: O(N+T)
void freq2(){

    int n;
    cin >> n;
    vector<int> a(n);

    // using hashing to pre-compute
    for(int i=0; i<n; i++){  // O(N)
        cin >> a[i];
        hsh[a[i]]++;
    }

    int t;
    cin >> t;
    while(--t){    // O(T)
        int n;
        cin >> n;
        cout << hsh[n] << endl;
    }
}

int main(){

    freq1();

    return 0;
}