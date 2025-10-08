#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Use sorting + sliding window to maximize frequency of a number by adding at most k.
- Sort array so we can handle numbers in increasing order.
- Use two pointers (i, j) to maintain a window of numbers we can equalize.
- Keep sum of the window to check if all numbers can become nums[j] with ≤ k additions.
- Shrink window from left if needed, update max frequency.
🕒 TC: O(n log n) for sorting + O(n) for window → O(n log n)
💾 SC: O(1) extra space
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum_n = 0;
        int maxi = 0;
        int i = 0, j = 0;

        while(j < nums.size()){
            sum_n += nums[j];
            if(nums[j] * 1LL * (j - i + 1) > sum_n + k * 1LL){
                sum_n -= nums[i];
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};
