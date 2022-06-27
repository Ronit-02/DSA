#include<iostream>
#include<vector>  // for 2d Vector
#include<algorithm>  // for sort()
#include<limits.h>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
     
        sort( arr.begin(), arr.end());

        int n = arr.size();
        int m = arr[0].size();
        vector <vector <int>>ans;

        print(arr, n, m);

        for(int i=0; i<n-1; i++){         // traversing i : 0 -> n-2

            for(int j=i+1; j<n; j++){       // traversing j : i+1 -> n-1

                if(arr[i][1] >= arr[j][0]){
                    
                    vector<int> v1;
                    v1.push_back(arr[i][0]);
                    v1.push_back(arr[j][1]);
                    ans.push_back(v1);
                }
            }
        }

        n = ans.size();
        m = ans[0].size();

        cout<<"New Pair: \n";
        print(ans, n, m);


    }

    void mergeUsingStack(vector< vector <int>>& arr){

        int n = arr.size();

        sort(arr.begin(), arr.end());    // sorting first

        stack< pair <int,int> >s;
        s.push( {arr[0][0], arr[0][1]} );     // pushing in stack

        for(int i=1; i<n; i++){

            int start1 = s.top().first;
            int end1 = s.top().second;
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if(end1 >= start2){          // if its bigger, increase the range of existing pair
                s.pop();
                end1 = max(end1, end2);
                s.push( {start1, end1} );
            }
            else{                       // if its smaller, just push in next pair
                s.push( {start2, end2} );
            }
        }

        stack<pair <int,int> >temp;        // For printing element bottom to top
        while (s.empty() == false)
        {
            temp.push( {s.top().first, s.top().second} );
            s.pop();
        }

        while(!temp.empty()){

            cout<< temp.top().first << " " << temp.top().second << endl;
            temp.pop();
        }
    }

    void print(vector <vector <int>>& arr, int n, int m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                cout<< arr[i][j] <<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    vector< vector <int> >arr { {1,3}, {8,10}, {2,6} };
    // vector< vector <int> >ans;

    Solution s;
    s.mergeUsingStack(arr);
    // int ans = s.merge(arr);
    // cout<<ans;
     
    return 0;
}