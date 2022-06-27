#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
    int n = arr.size();
	int s = m+1;
    int e = n-1;
    
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){

    vector<int>arr = {1,2,3,4,5,6};
    int n = 5;
    
    reverseArray(arr, 3);

    for(int i=0; i<n; ++i)
        cout<<arr[i]<<" ";

    return 0;
}