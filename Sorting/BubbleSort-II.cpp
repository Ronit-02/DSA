#include <iostream>
using namespace std;

////    Optimised Approach  ////

void bubbleSort(int a[], int n){

    int comp = 0;
    for(int times = 1; times <= n-1; times++){

        bool swapped = false;
        for(int i=0; i <= n-times-1; i++){

            if(a[i] > a[i+1]){

                swap(a[i], a[i+1]);
                swapped = true;
                comp++;
            }
        }
        if(swapped != true){
            break;
        }
    }
    cout<<"\nComparisons are: \n"<<comp;

}

int main() {

    int arr[] = {-2,4,3,-1,-12,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    cout<<"\nSorted Array: ";
    for(auto x: arr){
        cout<< x <<endl;
    }

        return 0;
}