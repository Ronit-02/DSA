#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int t;
	cin>>t;
	for(int i=0; i<t; i++){

		int n,w;
		cin >>n >>w;

		int *arr = new int[n];

		for(int j=0; j<n; j++){
			cin >>arr[j];
		}

        sort(arr, arr+n);
        int sum = 0;
        int count = 0;
        
        for(int a=n-1; a>=0; a--){
            
            sum += arr[a];
            count++;
            if(sum >=w){
                break;
            }
        }
		cout<<(n-count);
        cout<<endl;
	}

	return 0;
}
