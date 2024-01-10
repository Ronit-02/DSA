#include <iostream>
#include <vector>
using namespace std;

// Question: 
// calculate sum from (a,b) -> (c,d)

const int N = 1e3+10;
int pf[N][N];

// Test Cases: 10^5
// Time Complexity: O(T*N^2) -> 10^12 > 10^7 -> TLE
void matsum1(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1, vector<int> (n+1)); 

    for(int i=1; i<=n; i++){   // O(N^2)
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    int t;
    cin >> t;
    while(--t){   // O(T)
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        long long sum = 0;

        for(int i=a; i<=c; i++){    // O(N^2)
            for(int j=b; j<=d; j++){
                sum += arr[i][j];
            }
        }
        cout << sum << endl;
    }
}

// Time Complexity: O(N^2) -> 10^7 -> Pass
void matsum2(){

    int n;
    cin >> n;
    vector<vector<int>> arr(n+1, vector<int> (n+1));  

    for(int i=1; i<=n; i++){   // O(N^2)
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int t;
    cin >> t;
    while(--t){   // O(T)
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        long long sum = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
        cout <<  sum;
        cout << sum << endl;
    }
}

int main(){

    matsum2();

    return 0;
}