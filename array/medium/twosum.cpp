#include <iostream>
#include <unordered_map>
using namespace std;
// this question have type 1 and type 2 so i am solving for type 2 and mentioning type 1
// in comments
// bruite force Approach:

// First, we will use a loop(say i) to select the indices of the array one by one.
// For every index i, we will traverse through the remaining array using another loop(say j) to find the other number such that the sum is equal to the target (i.e. arr[i] + arr[j] = target).
vector <int> bruite(vector <int> arr,int target){
	int n = arr.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i]+arr[j]==target){
				return {arr[i],arr[j]}; // here if the case 1 we need to return true if we found the numbers
			}
		}
	}
	return {-1,-1}; // here we need to return false
}

// better approach:
// We will select the element of the array one by one using a loop(say i).
// Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
// If that element exists, then we will return “YES” for the first variant or we will return the current index i.e. i, and the index of the element found using map i.e. mp[target-arr[i]].
// If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
// Finally, if we are out of the loop, that means there is no such pair whose sum is equal to the target. In this case, we will return either “NO” or {-1, -1} as per the variant of the question.
vector <int> better(vector <int> arr,int target){
	int n = arr.size();
	unordered_map <int,int> mpp;
	for(int i=0; i<n; i++){
		int num = arr[i];
		int remp = target - num;
		if(mpp.find(remp)!=mpp.end()) return {mpp[remp],i}; // case 1 : true;
		mpp[num] = i;
	}
	return {-1,-1}; // case 1: true
} 

// now coming to the optimal approach
// The steps are the following:

// We will sort the given array first.
// Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
// Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
// If arr[left] + arr[right] > sum, we will decrement the right pointer.
// If arr[left] + arr[right] < sum, we will increment the left pointer.
// If arr[left] + arr[right] == sum, we will return the result.
// Finally, if no results are found we will return “No” or {-1, -1}.
// this will not work in test because it changes the whole conecept as it sortes the array
// and the array get worted based on it way
vector <int> optimal(vector <int> arr,int target){

}