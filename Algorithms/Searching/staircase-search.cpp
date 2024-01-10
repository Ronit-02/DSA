
#include <iostream>
#include <vector>

using namespace std;

pair <int,int> staircaseSearch(int r, int c, int arr[][4], int key){

    int row = 0;
    int col = c-1;
    vector <pair <int,int>> pos;

    while(row>=0 && row<r && col>=0 && col<c){

        if(arr[row][col] == key)
            return {row, col};
        else if(arr[row][col]>key)
            col--;
        else
            row++;
    }
    return {-1,-1};
}

int main(){

    int arr[][4]= {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    int r = 4;
    int c = 4;

    int key;
    cin>> key;

    pair <int,int> coords = staircaseSearch(r, c, arr, key);
    cout<< coords.first << "," << coords.second;

    return 0;
}