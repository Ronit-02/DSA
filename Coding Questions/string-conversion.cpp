#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int stringConversion(string s, vector<int>&arr) {
	
    // TC: O(n+m)
    
    int i = s.length()-1;
    int j = arr.size()-1;
    int sum = 0;
    int p = 0;
    
    while(i >= 0 && j > 0){
        
        cout << "i = " << i << endl;
        cout << "j = " << j << endl;
        cout << "sum = " << sum << endl;

        sum += pow(2,p) * (s[i]-'0');
        i--;
        p++;
        
        // reset case
        if(sum == arr[j]){
            sum = 0;
            p = 0;
            j--;
        }
    }
    
    if(j <= 0 && i < 0)
        return 1;
    return 0;
}

int main(){

    string s = "0000000";
    vector<int> arr = {7, 3, 1, 3, 1};

    cout << stringConversion(s, arr);
    return 0;
}
