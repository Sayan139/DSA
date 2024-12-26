// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <iostream>
using namespace std;
// bruite force approach
// Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

// Approach: 

// Use a for loop of ‘i’ from 0 to n.
// Use another for loop of j from ‘i+1’ to n.
// If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
// Return maxPro.
int bruite(vector <int> &arr){
	int maxpro = 0;
	int n = arr.size();
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[j]>arr[i]){
				maxpro = max(maxpro,arr[j]-arr[i]);
			}
		}
	}
	return maxpro;
}

//new using optimal approach
// Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

// Approach:

// Create a variable maxPro and store 0 initially.
// Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
// Run a for loop from 0 to n.
// Update the minPrice if it is greater than the current element of the array
// Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
// Return the maxPro.
int optimal(vector <int> arr){
	int n = arr.size();
	int maxpro = INT_MIN;
	int minprice = INT_MAX;
	for(int i=0; i<n; i++){
		minprice = min(minprice,arr[i]);
		maxpro = max(maxpro,arr[i]-minprice);
	}
	return maxpro;
}