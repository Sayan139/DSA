#include <iostream>
using namespace std;
// bruite force:
// The steps are as follows:

// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
// After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.
// Intuition: We will check the sum of every possible subarray and count how many of them are equal to k. To get every possible subarray sum, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will only consider those that are equal to k.

// Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.
int bruite(vector <int> arr,int k){
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum_of_sub = 0;
            for(int k=i; k<=j; k++){
                sum_of_sub += arr[k];
            }
            if(sum_of_sub == k) count++;
        }
    }
    return count;
}
//better approach:
// The steps are as follows:

// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
// Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. 
// After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.
// Intuition: If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

// Assume previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

// This is how we can remove the third loop and while moving j pointer, we can calculate the sum.
int better(vector <int> arr,int k){
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++){
        int sum_of_sub_array = 0;
        for(int j=i; j<n; j++){
            sum_of_sub_array += arr[i];
            if(sum_of_sub_array == k) count++;
        }
    }
    return count;
}
// optimal approach:
