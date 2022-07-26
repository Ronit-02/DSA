
#include <iostream>
using namespace std;

void spiralPrint(int arr[][4], int r, int c){

    //4 variables req
    int startRow = 0;
    int endRow = r-1;
    int startCol = 0;
    int endCol = c-1;

    while(startCol <= endCol && startRow <=endRow){

        //Start Row
        for(int col = startCol; col<=endCol; col++)
            cout<< arr[startRow][col] <<" ";

        //End Col
        for(int row = startRow+1; row<=endRow; row++)
            cout<< arr[row][endCol] <<" ";
        
        //End Row
        for(int col = endCol-1; col>=startCol; col--){
            //to avoid duplicate printing of rows when cols are less
            if(startRow==endRow)
                break;
            cout<< arr[endRow][col] <<" ";
            
        }

        //Start Col
        for(int row = endRow-1; row>=startRow+1; row--){

            //to avoid duplicate printing of rows when cols are less
            if(startCol==endCol)
                break;
            cout<< arr[row][startCol] <<" ";
        }

        // Update the variables to point to inner spiral
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
}

int main() {

    int arr[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int r = 4;
    int c = 4;

    cout<<"Array: \n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }

    cout<<"\nSpiral Print: \n";
    spiralPrint(arr, r, c);

	return 0;
}