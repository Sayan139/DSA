#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
This function finds the longest subarray with a sum of 0 by tracking the cumulative sum as we go through the array. For each element, we update the sum and check if it’s zero—if it is,
we’ve found a subarray from the start to the current index with a sum of 0. If the sum has been seen before, the subarray between the first occurrence and the current index has a sum of 0, 
and we update the longest length found so far. The hash map stores the first time a sum appears, helping us quickly check for zero-sum subarrays. Ultimately, 
we return the length of the longest subarray with a sum of 0.
Time Complexity: O(N), as we are traversing the array only once

Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
*/
int maxlen(vector <int> arr,int n){
   unordered_map<int,int> mpp;
   int maxi = 0;
   int sum = 0;
   for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum == 0)maxi=i+1;
    else{
        if(mpp.find(sum)!=mpp.end()){
            maxi = max(maxi,i-mpp[sum]);
        }else{
            mpp[sum]=i;
        }
    }
   } 
   return maxi;
}