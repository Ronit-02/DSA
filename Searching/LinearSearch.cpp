#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key){

    for(int i=0; i<n; i++){
        //check if the key is present at any index of the array
        if(key == arr[i]){
            return i;
        }
    }
    //if the key is not present return -1
    return -1;
}

int main() {

    int arr[] = {10,20,3,5,60};
    //size of the array
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    int index = linear_search(arr, n, key);
    if(index != -1){
        cout<<key <<" is present at the index " <<index;
    }else{
        cout<<key <<" is not present in the array";
    }

        return 0;
}