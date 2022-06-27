#include <iostream>
using namespace std;

//swapping adjacent digits till the largest element reaches at bottom (just like a bubble)
void bubbleSort(int a[], int n){

    int comp = 0;       //For calculating comparisons

    //Loop will run for n-1 times
    for(int times = 1; times <= n-1; times++){

        //Loop getting reduced in every iteration by 1
        for(int i=0; i <= n-times-1; i++){

            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);    //swapping adjacent element
                comp++;
            }
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