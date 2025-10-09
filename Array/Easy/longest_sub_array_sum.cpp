#include <bits/stdc++.h>
using namespace std;

/*
Optimal Solution (Handles Any Integers - Positive and Negative):
- Goal: Find the longest subarray with sum exactly equal to k.

Step-by-step reasoning:
1️⃣ We maintain a prefix sum while iterating through the array.
   - sum = sum of all elements from index 0 to current index i.
2️⃣ We use an unordered_map<int,int> (prefix) to store the first occurrence of each prefix sum.
   - Key = prefix sum value
   - Value = index where it first occurs
   Why first occurrence? Because the longest subarray comes from earliest occurrence.

3️⃣ Base Case: prefix[0] = -1
   - This handles the case where a subarray starting from index 0 sums to k.

4️⃣ For each element arr[i]:
   a) Add arr[i] to sum.
   b) Check if (sum - k) exists in prefix map.
      - Why? If sum - k was seen at index j, then the subarray (j+1 to i) has sum k.
      - Update maxlen = max(maxlen, i - prefix[sum - k])
   c) If sum is not in prefix, store it: prefix[sum] = i
      - Store first occurrence only to maximize length.
      
5️⃣ Return maxlen at the end.

🕒 TC: O(n) → Each element is visited once
💾 SC: O(n) → Hash map stores prefix sums
*/
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int,int> prefix;
    prefix[0] = -1;  // Handle subarray starting at index 0
    int sum = 0, maxlen = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Check if a previous prefix sum exists such that current subarray sums to k
        if(prefix.find(sum - k) != prefix.end()) {
            maxlen = max(maxlen, i - prefix[sum - k]);
        }

        // Store the first occurrence of sum
        if(prefix.find(sum) == prefix.end()) {
            prefix[sum] = i;
        }
    }

    return maxlen;
}

/*
Special Case: Only Positive Elements
- When array has only positive numbers, we can use two-pointer / sliding window approach.
- Why two pointers? Sum always increases as we add elements, so we can shrink window from left when sum > k.
- This is more space-efficient than prefix sum method.

Step-by-step:
1️⃣ Initialize two pointers i = 0 (start), j = 0 (end), sum = 0, maxlen = 0
2️⃣ Iterate while j < n:
   a) Add arr[j] to sum
   b) While sum > k, subtract arr[i] and move i++
   c) If sum == k, update maxlen = max(maxlen, j - i + 1)
3️⃣ Return maxlen

🕒 TC: O(n) → Each element added/subtracted once
💾 SC: O(1)
*/
int longestSubarrayPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int i = 0, sum = 0, maxlen = 0;

    for(int j = 0; j < n; j++) {
        sum += arr[j];

        // Shrink window from left if sum exceeds k
        while(sum > k) {
            sum -= arr[i];
            i++;
        }

        if(sum == k) {
            maxlen = max(maxlen, j - i + 1);
        }
    }

    return maxlen;
}
