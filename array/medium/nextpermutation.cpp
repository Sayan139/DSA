#include <iostream>
using namespace std;
// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).
// sol 1:
// Brute Force: Finding all possible permutations. 

// Approach :

// Step 1: Find all possible permutations of elements present and store them.

// Step 2: Search input from all possible permutations.

// Step 3: Print the next permutation present right after it.
// For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array. 
// Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).
// Space Complexity :
// Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).

// sol 2:
// Using in-built function

// C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.
void getNextPermutation(int arr[], int size) {
    next_permutation(arr, arr + size);
}
// this the steps of the above function if interviewer want explanation how this works?
// The steps are the following:

// Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
// For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
// To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
// If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
// So, in this case, we will reverse the whole array and will return it as our answer.
// If a break-point exists:
// Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
// Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
