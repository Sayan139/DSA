#include <bits/stdc++.h>
using namespace std;
int maxProfitOptimal(vector<int>& prices) {
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxPro = 0;

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Brute Force
    // int profit = maxProfitBruteForce(prices);

    // Optimal
    int profit = maxProfitOptimal(prices);

    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
