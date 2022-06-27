#include <iostream>
using namespace std;

void sumofSubarrays(int arr[], int n){

  //Creating a "Prefix Array"
  int prefix[100] = {0};
  prefix[0] = arr[0];

  for(int i=1; i<n; i++){
    prefix[i] = arr[i] + prefix[i-1];
  }

  //Calculating largest subarray
  int largest = 0;

  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
      sum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
      if(largest < sum)
      largest = sum;
    }
  }

  //printing largest subarray's sum
  cout <<largest;
}

int main(){

  int arr[]= {-2,3,4,-1,5,-12,6,1,3};
  int n = sizeof(arr)/sizeof(int);

  sumofSubarrays(arr, n);

  return 0;
}