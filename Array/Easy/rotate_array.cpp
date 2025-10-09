#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
We can rotate an array to the **right** or **left** using the reversal algorithm.

👉 Right Rotation by k steps:
Example: nums = [1, 2, 3, 4, 5, 6, 7], k = 3  
Result: [5, 6, 7, 1, 2, 3, 4]

🧠 Logic:
1️⃣ Reverse the first (n - k) elements.  
2️⃣ Reverse the last k elements.  
3️⃣ Reverse the entire array.

For k = 3:
- Step 1 → reverse [1,2,3,4] → [4,3,2,1,5,6,7]
- Step 2 → reverse [5,6,7] → [4,3,2,1,7,6,5]
- Step 3 → reverse all → [5,6,7,1,2,3,4]

🕒 TC: O(n) 💾 SC: O(1)

👉 Left Rotation by k steps:
Example: nums = [1, 2, 3, 4, 5, 6, 7], k = 3  
Result: [4, 5, 6, 7, 1, 2, 3]

🧠 Logic:
1️⃣ Reverse the first k elements.  
2️⃣ Reverse the remaining (n - k) elements.  
3️⃣ Reverse the entire array.

For k = 3:
- Step 1 → reverse [1,2,3] → [3,2,1,4,5,6,7]
- Step 2 → reverse [4,5,6,7] → [3,2,1,7,6,5,4]
- Step 3 → reverse all → [4,5,6,7,1,2,3]

🕒 TC: O(n) 💾 SC: O(1)
*/
class Solution {
public:
    // Helper function to reverse a portion of the array
    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++, end--;
        }
    }
    // 👉 Right rotation by k steps
    void rotateRight(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle k > n

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
    // 👉 Left rotation by k steps
    void rotateLeft(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle k > n

        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, n - 1);
    }
};
