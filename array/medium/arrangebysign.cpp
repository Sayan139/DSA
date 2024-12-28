#include <iostream>
using namespace std;
// question : https://leetcode.com/problems/rearrange-array-elements-by-sign/
//bruite force approach:
// Approach:

// In this simple approach, since the number of positive and negative elements are the same, we put positives into an array called “pos” and negatives into an array called “neg”.
// After segregating each of the positive and negative elements, we start putting them alternatively back into array A.
// Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
// This approach uses O(N+N/2) of running time due to multiple traversals which we’ll try to optimize in the optimized approach given below.
// Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
// Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
vector <int> bruite(vector <int> arr){
	int n = arr.size();
	vector <int> pos;
	vector <int> neg;
	for(int i=0; i<n; i++){
		if(arr[i]>0) pos.push_back(arr[i]);
		else neg.push_back(arr[i]);
	}
	for(int i=0; i<n/2; i++){
		arr[2*i] = pos[i];
		arr[(2*i)+1] = neg[i];
	}
	return arr;
}

// now coming to optimal approach
// Approach:

// In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.
// We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).
// Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.
// When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.
// Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.

// Space Complexity:  O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.
vector <int> optimal(vector <int> arr){
	int n = arr.size();
	int posindex =0;
	int negindex =1;
	vector <int> res;
	for(int i=0; i<n; i++){
		if(arr[i]>0){
			res[posindex] = arr[i];
			posindex += 2;
		}else{
			res[negindex] = arr[i];
			negindex += 2;
		}
	}
	return res;
}

//variety 2:
// Problem Statement:

// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.
// Intuition:

// In this variety, the number of positive and negative numbers shall not necessarily be equal to each other in the given array. So, there can be two cases possible: either the positive elements exceed the negatives or the negatives exceed the positives. So, instead of using the optimal solution discussed for the variety-1 above, we’ll fall back to the brute force solution where we create separate arrays for storing positives and negatives and then put them back into the array alternatively. The remaining negative or positive elements are added to the array at last.

// Approach:

// In this problem, first, we create a neg array and a pos array for storing all the negative and positive elements of array A separately.
// Now, similar to the Brute force approach for variety-1, we start putting elements of pos and neg array alternatively back into array A.
// Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
// After all the elements are added to the index where positives were equal to the negatives, we now put all the remaining elements ( whether positive or negative) at the last of the array by running a single loop from pos.size() to neg.size() {if positives < negatives} or neg.size() to pos.size() {if negatives < positives}.
vector <int> varity2(vector <int> arr){
	int n = arr.size();
	vector <int> pos;
	vector <int> neg;
	for(int i=0; i<n; i++){
		if(arr[i]>0) pos.push_back(arr[i]);
		else neg.push_back(arr[i]);
	}
	if(pos.size() < neg.size()){
		for(int i=0; i<pos.size(); i++){
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}
		int index = pos.size()*2;
		for(int i=pos.size(); i<neg.size(); i++){
			arr[index] = pos[i];
			index++;
		}
	}
	else{
		for(int i=0; i<neg.size(); i++){
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}
		int index = neg.size();
		for(int i=neg.size(); i<pos.size(); i++){
			arr[index] = neg[i];
			index++;
		}
	}
	return arr;
}