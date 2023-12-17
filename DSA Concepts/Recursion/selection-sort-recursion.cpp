#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>& arr, int i){   
    
    // Base Case
    if(i == arr.size()-1)
        return;

    // Ek case solve krle, baaki recursion dekhlega
    for(int j = i+1; j < arr.size(); j++){
        if(arr[j] < arr[i])
            swap(arr[i], arr[j]);
    }
    
    //Recursive Call
    selectionSort(arr, i+1);   
}
    
int main(){

    vector<int>arr = {2,5,1,4,3};
    
    selectionSort(arr, 0);

    for(int i=0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";

    return 0;
}



