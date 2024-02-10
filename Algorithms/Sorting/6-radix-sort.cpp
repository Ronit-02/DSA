#include <iostream>                                                                                                                                                 
#include <vector>                                                                                                                                                   
using namespace std;                                                                                                                                                                                                                                                                                                                    

// 126 23 34 454 23 233 22 15                                                                                                                                       
//count: 0   1   2   3   4   5   6   7   8   9                                                                                                                      
//count:|0| |0| |1| |2| |2| |1| |1| |0| |0| |0|                                                                                                                     
//count:|0| |0| |1| |3| |5| |6| |7| |7| |7| |7|                                                                                                                                                                                                                                                                                         
//Function to find max in an array
int getMax(int arr[], int n){

        int largest = -1;
        for(int i=0; i<n; i++){
                largest = max(largest, arr[i]);
        }
        return largest;
}

// A function to do counting sort of arr[] according to
// the digit represented by pos(placevalue).
void countSort(int arr[], int n, int pos){

        vector<int> count(10, 0);       //numbers to be stored are ranging 0-9 -> size=10
        vector<int> newarr(n, 0);

        //making count array
        for(int i=0; i<n; i++){
                count[ (arr[i]/pos) % 10]++;
        }

        //updating count array
        for(int i=1; i<10; i++){
                count[i] += count[i-1];
        }

        //creating new array
        for(int i = n-1; i >= 0; i--){
                newarr[ count[ (arr[i] / pos) % 10] - 1 ] = arr[i];
                count[(arr[i] / pos) % 10]--;
        }

        //copying values to original array
        for(int i=0; i<n; i++){
                arr[i] = newarr[i];
        }
}

//use of count sort and sort acc. to place value (10's, 100's,....)
void radixSort(int arr[], int n){

        //finding the max element in array (to know the amt of placevalues present)
        int max = getMax(arr, n);

        //Calling count sort for diff pacevalues
        for(int pos=1; max/pos > 0; pos *= 10){

                countSort(arr, n, pos);
        }
}

int main() {

        int arr[] = {4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, n);

    for(int x : arr){
        cout<< x <<endl;
    }

        return 0;
}