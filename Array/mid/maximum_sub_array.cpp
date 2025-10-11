#include <bits/stdc++.h>
using namespace std;
/*
Optimal Approach (Maximum Sum Subarray of Non-Negative Numbers)

Approach:
1. Use variables to track:
   - sum → current subarray sum
   - maxSum → best (maximum) subarray sum found so far
   - start → start index of current subarray
   - bestStart, bestEnd → indices of the best subarray so far

2. Traverse the array:
   - If arr[i] >= 0:
        • Add arr[i] to sum.
        • Check if we found a better subarray:
            - If sum > maxSum → update bestStart, bestEnd, and maxSum.
            - If sum == maxSum → choose the longer subarray 
              (i - start > bestEnd - bestStart).
   - If arr[i] < 0:
        • Reset sum to 0 and move start to i + 1 (new subarray begins).

3. After the loop:
   - If no non-negative numbers were found → return {-1}.
   - Else return the elements between bestStart and bestEnd (inclusive).

Why the tie-breaking condition?
- When two subarrays have the same sum, we prefer the longer one:
  (sum == maxSum && (bestStart == -1 || i - start > bestEnd - bestStart))
  ensures that if sums are equal, the subarray with a greater length is chosen.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0, maxSum = -1;
        int start = 0, bestStart = -1, bestEnd = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                sum += arr[i];

                // Check if we found a better or longer subarray
                if (sum > maxSum || (sum == maxSum && 
                    (bestStart == -1 || i - start > bestEnd - bestStart))) {
                    maxSum = sum;
                    bestStart = start;
                    bestEnd = i;
                }
            } else {
                // Reset when negative element found
                sum = 0;
                start = i + 1;
            }
        }

        // If no valid subarray found
        if (bestStart == -1) return {-1};

        // Return the best subarray
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestEnd + 1);
    }
};
/*
3. Optimal Approach (Kadane’s Algorithm)

Approach:
1. Initialize:
   - sum = 0 → stores the current subarray sum.
   - maxi = INT_MIN → stores the maximum sum found so far.

2. Traverse the array:
   - Add nums[i] to sum (sum += nums[i]).
   - Update maxi = max(maxi, sum).
   - If sum becomes negative (sum < 0), reset sum = 0.
     → Because a negative prefix can’t contribute to a future maximum subarray.

3. After traversal, maxi contains the largest possible sum
   of any contiguous subarray.

Intuition:
- Keep adding numbers to the current subarray sum.
- If the sum drops below 0, start fresh from the next element.
- This ensures only positive-contributing parts are carried forward.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }

    return maxi;
}
