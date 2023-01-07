#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int M = 1e7+9;
const int N = 1e5+10;
ll fact[N];

// Time Complexity: O(N*T)
void fact1(){

    int t;     
    cin >> t;
    while(--t){     // O(T)
        int n;
        cin >> n;
        ll fact = 1;
        for(int i=1; i<=n; i++){   // O(N)
            fact = (fact*i) % M;
        }
        cout << fact << endl;
    }
}

// Time Complexity: O(N+T)
void fact2(){

    // Pre computing values for N
    fact[0] = fact[1] = 1;
    for(int i=2; i<N; i++){    // O(N)
        fact[i] = fact[i-1] * i;
    }

    int t;     
    cin >> t;
    while(t--){     // O(T)
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
}
int main(){
    
    fact2();

    return 0;
}