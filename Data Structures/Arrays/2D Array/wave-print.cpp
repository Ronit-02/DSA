#include <iostream>
#include <vector>
using namespace std;

vector <int> wavePrint(int m, int n, vector< vector<int> > arr){        //m = rows,  n = cols

    int startRow = 0;
    int endRow = m-1;
    int startCol = 0;
    int endCol = n-1;
    vector<int> temp;

    while(endCol>=startCol){

        if(endCol % 2 != 0)     //for odd col no
            for(int row=startRow; row<=endRow; row++){
                // cout <<arr[row][endCol] <<" ";
                temp.push_back(arr[row][endCol]);
            }

        else
            for(int row=endRow; row>=startRow; row--){
                // cout <<arr[row][endCol];
                temp.push_back(arr[row][endCol]);
            }

        endCol--;
    }
    return temp;
}

int main(){

    vector <vector<int> > arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    vector<int> output;
    int r = 5;
    int c = 4;

    cout<<"Array: \n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }

    output = wavePrint(r, c, arr);

    cout<<"\nWave Print: \n";
    for(int i=0; i<output.size(); i++){
        cout<< output[i] << " ";
    }
    return 0;
}