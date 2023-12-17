#include <iostream>
using namespace std;

//Largest Sum of Subarray Bruter Force approach
void sumofSubarrays(int arr[], int n){

    int largest = 0;
    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){

            int sum = 0;

            for(int k=i; k<=j; k++){
                sum += arr[k];
            }

            cout <<sum <<endl;
            if(sum > largest)
                largest = sum;
        }
        cout<<endl;
    }
    cout <<"Largest sum is " <<largest;
}

void printSubarrays(int arr[], int n){

    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){
            // cout<<i <<"," <<j <<" ";
            for(int k=i; k<=j; k++){
                cout<< arr[k] <<",";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main() {
        int arr[] = {1,2,3,4,5};

  int n = sizeof(arr)/sizeof(int);

  printSubarrays(arr, n);

  sumofSubarrays(arr, n);

        return 0;
}