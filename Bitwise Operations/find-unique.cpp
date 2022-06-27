#include<iostream>
#include<limits.h>

using namespace std;

int main(){

    int arr[] = {1,2,3,1,3,2,4};
    int n = sizeof(arr)/sizeof(int);

    int ans = 0;

    for(int i=0 ; i<n; i++){
        ans = ans^arr[i];
    }    

    if(ans == 0)
        cout<<"No unique number exists";
    else
        cout<< "Unique number is " << ans;
    return 0;
}