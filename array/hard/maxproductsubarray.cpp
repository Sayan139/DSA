#include <bits/stdc++.h>
using namespace std;
/*
in the bruite force and bwtter approach we are just iterating with nested loop and find the maximum 
product of sub array in case of bruite it will cost O(n^3) because of the third extra loop for calculating 
prodcut and in better approach it will initialize before 2nd loop so the tc reduces to O(n^2) and in both cases
sc:O(1)
*/
int bruite(vector <int> arr){
    int n = arr.size();
    int result = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int prod = 1;
            for(int k=i; j<=j; k++){
                prod *= arr[i];
            }result = max(result,prod);
        }
    }return result;
}
int better(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }result = max(result,p);
    }return result;
}
/*
optimal 1:observation
Algorithm: 

We will first declare 2 variables i.e. ‘pre’(stores the product of the prefix subarray) and ‘suff’(stores the product of the suffix subarray). They both will be initialized with 1(as we want to store the product).
Now, we will use a loop(say i) that will run from 0 to n-1.
We have to check 2 cases to handle the presence of 0:
If pre = 0: This means the previous element was 0. So, we will consider the current element as a part of the new subarray. So, we will set ‘pre’ to 1.
If suff = 0: This means the previous element was 0 in the suffix. So, we will consider the current element as a part of the new suffix subarray. So, we will set ‘suff’ to 1.
Next, we will multiply the elements from the starting index with ‘pre’ and the elements from the end with ‘suff’. To incorporate both cases inside a single loop, we will do the following:
We will multiply arr[i] with ‘pre’ i.e. pre *= arr[i].
We will multiply arr[n-i-1] with ‘suff’ i.e. suff *= arr[n-i-1].
After each iteration, we will consider the maximum among the previous answer, ‘pre’ and ‘suff’ i.e. max(previous_answer, pre, suff).
Finally, we will return the maximum product.
Time Complexity: O(N), N = size of the given array.
Reason: We are using a single loop that runs for N times.

Space Complexity: O(1) as No extra data structures are used for computation.
*/
int optimal1(vector <int> arr){
    int n = arr.size();
    int pre = 1,suff = 1;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n-i-1];
        ans = max(ans,max(pre,suff));
    }
    return ans;
}//this should be used in interview
/*
optimal 2:  Kadane's Algorithm
The pick point for this problem is that we can get the maximum product from the product of two negative numbers too.

Following are the steps for the approach:

Initially store 0th index value in prod1, prod2 and result.
Traverse the array from 1st index. 
For each element, update prod1 and prod2.
Prod1 is maximum of current element, product of current element and prod1, product of current element and prod2
Prod2 is minimum of current element, product of current element and prod1, product of current element and prod2
Return maximum of result and prod1
Time Complexity: O(N)

Reason: A single iteration is used.

Space Complexity: O(1)

Reason: No extra data structure is used for computation
*/
int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        result = max(result,prod1);
    }
    return result;
}