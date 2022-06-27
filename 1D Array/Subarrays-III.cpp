#include <iostream>

using namespace std;

        //          "Kadane's Algorithm"            //
void sumofSubarrays(int arr[], int n){

    int cs = 0;         //current sum
    int ms = 0;         //maximum sum
    for(int i=0; i<n; i++){

        cs += arr[i];
        if(cs < 0)
            cs = 0;

        if(ms < cs)
            ms = cs;
    }

    cout<<ms;
}

int main()
{
    int arr[] = {-2,3,4,-1,5,-12,6,1,3,2};
    int n = sizeof(arr)/sizeof(int);

    sumofSubarrays(arr, n);

    return 0;
}