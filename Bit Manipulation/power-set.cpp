#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// TC: O(2^n * n)
// Intuition: 
// going through all the numbers (0 -> 2^n-1), 
// only set bit index(1) is taken into sub-string
vector<string> subsequences(string str){

	int n = str.length();
	vector<string>ans;

	for (int num=0; num<(1 << n); num++) {
		string substr = "";

		for (int i=0; i<n; i++) {

			// check if the ith bit is set or not
			if (num & (1 << i)) {
				substr += str[i];
			}
		}
		if (substr.length() > 0) {
			ans.push_back(substr);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main(){

    string str = "abc";

    vector<string> ans = subsequences(str); 
    for(auto it:ans)
        cout << it << ", ";

    return 0;
}