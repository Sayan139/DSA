#include <iostream>
#include <map>
using namespace std;
// bruite force approach
//  The steps are as follows:

// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
// If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.
// Time Complexity: O(N3) approx., where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
int bruiteforce1(vector<int> &arr, long long k)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = 0;
            for (int idx = i; idx <= j; idx++)
            {
                sum += arr[idx];
            }

            if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
//optimizing the bruite force approach
int bruiteforce2(vector <int> arr,int k){
    int n = arr.size();
    int maxlen= 0;
    for(int i=0; i<n; i++){
        long long s = 0;
        for(int j=i; j<n; j++){
            s += arr[j];
            if(s==k){
                maxlen = max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}


//using the better solution
// The steps are as follows:

// First, we will declare a map to store the prefix sums and the indices.
// Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
// For each index i, we will do the following:
// We will add the current element i.e. a[i] to the prefix sum.
// If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
// We will calculate the prefix sum i.e. x-k, of the remaining subarray.
// If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
// If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. [Detailed discussion in the edge case section]
// In this approach, we are using the concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending at index i, simply means the sum of all the elements of that subarray.

// Observation: Assume, the prefix sum of a subarray ending at index i is x. In that subarray, we will search for another subarray ending at index i, whose sum equals k. Here, we need to observe that if there exists another subarray ending at index i with sum k, then the prefix sum of the rest of the subarray will be x-k. 
// Now, for a subarray ending at index i with the prefix sum x, if we remove the part with the prefix sum x-k, we will be left with the part whose sum is equal to k. And that is what we want.

// That is why, instead of searching the subarrays with sum k, we will keep track of the prefix sum of the subarrays generated at every index using a map data structure. 

// In the map, we will store every prefix sum calculated, with its index in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the index i.e. preSumMap[x-k] where the subarrays with the prefix sum x-k occur. Then we will simply subtract the index i.e. preSumMap[x-k] from the current index i to get the length of the subarray i.e. len = i -preSumMap[x-k].

// We will apply the above process for all possible indices of the given array. The possible values of the index i can be from 0 to n-1(where n = size of the array).

// Edge Case: Why do we need to check the map if the prefix sum already exists? In the algorithm, we have seen that at step 3.4, we are checking the map if the prefix sum already exists, and if it does we are not updating it. Let’s understand the reason by considering the following example:
// Assume the given array is {2, 0, 0, 3}. If we apply the algorithm to the given array without checking
// In steps 2 and 3 the element at index i is 0. So, in those steps, the prefix sum remains the same but the index is getting updated in the map. Now, when index i reaches the end, it calculates the length i.e. i-preSumMap[rem] = 3-2 = 1. Here it is considering only the subarray [3] which is incorrect as the longest subarray we can get is [0, 0, 3] and hence the length should be 3.

// Now, to avoid this edge case i.e. to maximize the calculated length, we need to observe the formula we are using to calculate the length i.e. len = i - preSumMap[rem].

// Now, if we minimize the term preSumMap[rem] (i.e. the index where the subarray with sum x-k ends), we will get the maximum length. That is why we will consider only the first or the leftmost index where the subarray with sum x-k ends. After that, we will not update that particular index even if we get a similar subarray ending at a later index.

// So, we will check the map before inserting the prefix sum. If it already exists in the map, we will not update it but if it is not present, we will insert it for the first time.

// Note: For a better understanding of intuition, please watch the video at the bottom of the page.
// time complexity O(n)
// space complexity O(n)
int longestsubarray(vector <int> arr,int k){
    int n = arr.size();
    map<long long,int> preseummap;
    long long sum = 0;
    int index = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum==k){
            index = max(index,i+1);
        }
        if(preseummap.find(sum-k)!=preseummap.end()){
            int len = i-preseummap[sum-k];
            index = max(index,len);
        }
        if(preseummap.find(sum)==preseummap.end()){
            preseummap[sum] = i;
        }
    }
    return index;
}
// optimal solution
// The steps are as follows:
// First, we will take two pointers: left and right, initially pointing to the index 0.
// The sum is set to a[0] i.e. the first element initially.
// Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
// Inside the loop, we will do the following:
// We will use another while loop and it will run until the sum is lesser or equal to k.
// Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
// After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
// Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
// Finally, we will return the maximum length.
// Intuition: We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray and the right pointer denotes the ending index. Now as we want the longest subarray, we will move the right pointer in a forward direction every time adding the element i.e. a[right] to the sum. But when the sum of the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of the subarray as well as to decrease the sum. Thus, we will consider the length of the subarray whenever the sum becomes equal to k.
// The below dry run will clarify the intuition.

int optimal(vector <int> arr,int k){
    int n = arr.size();
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxlen = 0;
    while(right<n){
        while(left <= n && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum==k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right<=n) sum += arr[right];
    }
    return maxlen;
}