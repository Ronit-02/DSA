#include <iostream>
#include <vector>
using namespace std;

// Question: 
// calculate sum from (a,b) -> (c,d)

const int N = 1e7+10;
int pf[N][N];

// Time Complexity:
void matsum1(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (n));
    for()

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

// Time Complexity: 
void matsum2(){

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

    matsum2();

    return 0;
}