/////   Question from SPOJ.com    //////

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

bool isSafe(vector<int> &arr, int n, int m, int mid){

    int height = 0;

    for(int i=0; i<n; i++){

        if(arr[i] >= mid)
            height += (arr[i] - mid);

        if(height >= m)
            return true;
    }
    return false;
}

int main(){

    int n;       // no of trees
    int m;       // metres of wood req
    cin >> n >> m;

    vector <int> arr(n, -1);

    int Max = -1;
    for(int i=0; i<n; ++i){
        cin>> arr[i];
        Max = max(Max, arr[i]);
    }

    int ans = -1;
    int s = 0;
    int e = Max;
    int mid = s + (e-s)/2;

    while(s <= e){

        if(isSafe(arr, n, m, mid)){
            ans = mid;
            s = mid+1;
        }
        else
            e = mid-1;

        mid = s + (e-s)/2;
    }

    cout << "Output:\n " << ans;

    return 0;
}