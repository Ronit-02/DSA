#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

// Intuition: Saving the min price as we go...
int f1(vector<int> &prices)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i=1; i<prices.size(); i++){

        int cost = prices[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4}; // 5
    cout << f1(prices);

    return 0;
}