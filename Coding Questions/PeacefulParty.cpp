#include <iostream>
using namespace std;

int main() {

	int t;
	cin>>t;
	for(int i=0; i<t; i++){		//test cases

		int a,b,c;
		cin>>a >>b >>c;

		if(a+c > b)
			cout<<(a+c);
		else 
			cout<<b;
			
		cout<<endl;
	}	

	return 0;
}
