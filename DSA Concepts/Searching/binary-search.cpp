#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key){

    int start = 0, end = n-1;

    while(start <= end){

        int mid = (start + end)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    //if it is not present and loop termminates
    return -1;
}

int main() {

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    int index = binary_search(arr, n, key);
    if(index != -1){
        cout<<key <<" is present at index " <<index;
    }else{
        cout<<key <<" is NOT Present";
    }
        return 0;
}