#include <iostream>
#include <vector>
using namespace std;

// Question: 
// calculate sum from l -> r

const int N = 1e7+10;
int pf[N];

// Time Complexity: O(N + N*T)
void arrsum1(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){  // O(N)
        cin >> a[i];
    }

    int t;
    cin >> t;
    while(--t){   // O(T)
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        for(int i=l; i<=r; i++){  // O(N)
            sum += a[i];
        }
        cout << sum << endl;
    }
}

// Time Complexity: O(N+T)
void arrsum2(){

    int n;
    cin >> n;
    vector<int> a(n+1, 0);

    // using hashing to pre-compute
    for(int i=1; i<=n; i++){  // O(N)
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }

    int t;
    cin >> t;
    while(--t){    // O(T)
        int n;
        cin >> n;
        cout << pf[n] << endl;
    }
}

int main(){

    arrsum2();

    return 0;
}