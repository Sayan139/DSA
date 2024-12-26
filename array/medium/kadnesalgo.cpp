#include <iostream>
using namespace std;
// bruite force approach
// Intuition:

// We will check the sum of every possible subarray and consider the maximum among them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will consider the maximum one.
// The steps are as follows:

// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
int bruite(vector <int> arr){
	int n = arr.size();
	int maxi = INT_MIN;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int sum = 0;
			for(int k=i; k<=j k++){
				sum += arr[k];
			}
			maxi = max(maxi,sum);
		}
	}
	return maxi;
}
//  better approach:
// Intuition: If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

// Assume previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

// This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

// Approach:

// The steps are as follows:

// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
// Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
// Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. Among all the sums the maximum one will be the answer.

int better(vector <int> arr){
	int n = arr.size();
	int maxi = INT_MIN;
	for(int i=0; i<n; i++){
		int sum =0;
		for(int j=0; j<n; j++){
			sum += arr[j];
			maxi = max(maxi,sum);
		}
	}
	return maxi;
}

// optimal approach
// Intuition:

// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

// Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

// Thus we can solve this problem with a single loop.

// Approach:

// The steps are as follows:

// We will run a loop(say i) to iterate the given array.
// Now, while iterating we will add the elements to the sum variable and consider the maximum one.
// If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
// Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
// For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

// This is applicable to all the approaches discussed above.

// But if this case is not explicitly mentioned we will not consider this case.

int optimal(vector <int> arr){
	int n = arr.size();
	int maxi = INT_MIN;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
		if(sum > maxi) maxi = sum;
		if(sum < 0) sum = 0;
	}
	// To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;
	return maxi;
}

// followup question
// There might be more than one subarray with the maximum sum. We need to print any of them.

// Intuition: Our approach is to store the starting index and the ending index of the subarray. Thus we can easily get the subarray afterward without actually storing the subarray elements.

// If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

// So, we will keep a track of the starting index inside the loop using a start variable.
// We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.
// The rest of the approach will be the same as Kadane’s Algorithm.

// Note: For a better understanding of intuition, please watch the video at the bottom of the page.

// here in simple words we need to give the subarray to show and sum to print

void followup(vector <int> arr){
	int n = arr.size();
	int maxi = INT_MAX;
	int sum = 0;
	int start = 0;
	int ansStart = -1,ansend = -1;
	for(int i=0; i<n; i++){
		if(sum == 0){
			start  = i;
		}
		sum += arr[i];
		if(sum > maxi){
			maxi = sum;
			ansStart = start;
			ansend = i;
		}
		if(sum < 0) sum = 0;
	}
	cout << "The subarray is : \n[" << endl;
	for(int i=ansStart; i<=ansend; i++){
		cout << arr[i] << ",";
	}
	cout << "]" << endl;
	cout << "The max sum is: " << maxi << endl;
}






