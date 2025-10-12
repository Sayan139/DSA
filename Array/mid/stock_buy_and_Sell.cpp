#include <bits/stdc++.h>
using namespace std;

/*
Problem: Best Time to Buy and Sell Stock

Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
in the future to sell that stock. Return the maximum profit you can achieve. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6).
*/

/*
1. Brute Force Approach

Algorithm / Intuition:
Try every possible pair of buy and sell days and calculate the profit.
Keep track of the maximum profit.

Approach:
1. Run two nested loops:
   - Outer loop (i) for buying day.
   - Inner loop (j) for selling day (j > i).
2. If prices[j] > prices[i], calculate profit = prices[j] - prices[i].
3. Keep track of the maximum profit.

Time Complexity:  O(N^2)
Space Complexity: O(1)
*/
int maxProfitBruteForce(vector<int>& prices) {
    int n = prices.size();
    int maxPro = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[j] > prices[i]) {
                maxPro = max(maxPro, prices[j] - prices[i]);
            }
        }
    }

    return maxPro;
}

/*
2. Optimal Approach

Algorithm / Intuition:
We can maintain the minimum price seen so far and calculate profit if we sell today.
Update the maximum profit along the way.

Approach:
1. Initialize minPrice = INT_MAX, maxPro = 0.
2. Traverse prices array:
   - Update minPrice = min(minPrice, prices[i]).
   - Calculate profit = prices[i] - minPrice.
   - Update maxPro = max(maxPro, profit).
3. Return maxPro.

Time Complexity:  O(N)
Space Complexity: O(1)
*/
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
