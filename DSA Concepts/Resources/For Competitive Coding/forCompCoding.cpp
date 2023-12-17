#include <iostream>
typedef unsigned long long int ll;  //needed to increase readability of code

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);   //increasing speed of cin and cout (as in scanf and printf)
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE    //online judge will ignore this
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >>t;
    cout<< sizeof(t) <<endl;
    cout<< t;

    return 0;
}