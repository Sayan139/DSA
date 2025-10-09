#include <bits/stdc++.h>
using namespace std;

/*
Optimal Solution:
- Traverse the array and count consecutive 1s.
- Reset count to 0 when a 0 is encountered.
- Track the maximum count seen so far.
🕒 TC: O(n) 💾 SC: O(1)
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 1) count++;
        else {
            maxi = max(maxi, count);
            count = 0;
        }
    }
    return max(count, maxi);
}
