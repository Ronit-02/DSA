#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    // Jagged array is array of arrays such that member arrays can be of different sizes
    //, i.e., we can create a 2-D array but with a variable number of columns in each row.
    
    int n = 3;
    // cin >> n;

    int **arr = new int*[n];
    arr[0] = new int[1];
    arr[1] = new int[2];
    arr[2] = new int[3];

    // input
    for(int i=0; i < n; i++){
        for(int j=0; j < i+1; j++){
            cin >> arr[i][j];
        }
    }

    // output
    for(int i=0; i < n; i++){
        for(int j=0; j < i+1; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}