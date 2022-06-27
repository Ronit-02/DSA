#include<iostream>

using namespace std;

int binarySearch(int arr[], int s, int e, int key){
	
    int mid = s + (e-s)/2;
    while(s <= e){

        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            s = mid+1;
        else
            e = mid-1;
        mid = s + (e-s)/2;
	}
	return -1;
}

int main(){

	int arr[] = {1,3,5,7,9};
	
    int low = 0;
    int high = 1;
    int key = 5;
    int x = arr[high];

    while(x < key){
        low = high;
        high = 2*high;
        x = arr[high];
    }

    int ans = binarySearch(arr, low, high, key);
    if(ans == -1)
        cout<< "Not Found";
    else
        cout<<"Found at "<< ans;

	return 0;
}
