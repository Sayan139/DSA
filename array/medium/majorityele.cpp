#include <iostream>
using namespace std;
// bruite force approach:
// The steps are as follows:

// We will run a loop that will select the elements of the array one by one.
// Now, for each element, we will run another loop and count its occurrence in the given array.
// If any element occurs more than the floor of (N/2), we will simply return it.
// Time Complexity: O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). 
// Space Complexity: O(1) as we use no extra space.
int bruite(vector <int> arr){
	int n = arr.size();
	for(int i=0; i<n; i++){
		int cnt = 0;
		for(int j=0; j<n; j++){
			if(arr[j]==arr[i]) cnt++;
		}
		if(cnt >= (n/2)) return arr[i];
	}
	return -1;
}
// better solution
// Use a better data structure to reduce the number of look-up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again and again - so we have to reduce that also.

// Approach: 

// Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
// Here the key will be the element of the array and the value will be the number of times it occurs. 
// Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
// If yes, return the key 
// Else iterate forward.
// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

// Space Complexity: O(N) as we are using a map data structure.
int better(vector <int> arr){
	int n = arr.size();
	unordered_map <int,int> mpp;
	for(int i=0; i<n; i++){
		mpp[arr[i]]++;
	}
	for(auto it:mpp){
		if(it.second > n/2) return it.first;
	}
	return -1;
}

//optimal approach:
// If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

// After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

// Approach: 

// Initialize 2 variables:
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through the given array.
// If Count is 0 then store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1.
// If they are different decrease the Count by 1.
// The integer present in Element should be the result we are expecting 
int better(vector <int> arr){
	int n = arr.size();
	int cnt =0;
	int ele;
	for(int i=0; i<n; i++){
		if(cnt == 0){
			cnt = 1;
			ele = arr[i];
		}
		else if(ele == arr[i]) cnt++;
		else cnt--;
	}
	int cnt1 =0;
	for(int i=0; i<n; i++){
		if(arr[i]==ele) cnt1++;
	}
	if(cnt1 > (n/2)) return cnt1;
	return -1;
}







