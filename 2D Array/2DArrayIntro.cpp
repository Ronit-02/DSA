
#include <iostream>
using namespace std;

void print(int arr[][100], int m, int n){

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main() {

    //given constraints row=100, col=100
    int arr[100][100];

    int row,col;
    cin>> row >>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>> arr[i][j];
        }
    }
    print(arr, row, col);

	return 0;
}

